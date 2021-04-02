//
// Created by molna on 2021. 04. 02..
//
#include "App.h"

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

ALLOCATE_IMPL(circular_buffer_t);
DEALLOCATE_IMPL(circular_buffer_t);

void exit_app(return_code_t rc)
{
  print_error(rc);
  exit(EXIT_FAILURE);
}

circular_buffer_t* initialize_buffer()
{
  //alloc circular buffer
  circular_buffer_t* buffer = allocate_circular_buffer_t();
  if (!buffer) {
    exit_app(ALLOCATION_FAILURE);
  }
  return_code_t rc = set_circular_buffer_defaults_event_t(buffer, CIRCULAR_BUFFER_SIZE);
  if (rc != SUCCESS) {
    exit_app(rc);
  }
  rc = allocate_data_event_t(buffer);
  if (rc != SUCCESS) {
    exit_app(rc);
  }
  return buffer;
}

void deallocate_buffer(circular_buffer_t* buffer)
{
  deallocate_data_event_t(buffer);
  deallocate_circular_buffer_t(buffer);
}

void show_command_options()
{
  printf("Please select from the following options:\n");
  printf(" -Add patient: a\n");
  printf(" -Modify patient: m\n");
  printf(" -Remove patient: r\n");
  printf(" -Show all records: s\n");
  printf(" -Exit: e\n");
  printf(" -Help: h\n");
  printf("Please select a key to continue: ");
}

return_code_t get_year_input(uint16_t* year_of_birth)
{
  uint8_t tries = 0;
  do {
    printf("Please enter patient's year of birth: ");
    scanf("%hd", year_of_birth);
    while ((getchar()) != '\n');
    ++tries;
  } while (!is_valid_year(current_year, *year_of_birth) && tries != 3);

  if (tries == 3 && !is_valid_year(current_year, *year_of_birth))
  {
    printf("Too many invalid input, aborting...");
    return VALIDATION_FAILURE;
  }
  return SUCCESS;
}

void get_name_input(char* name)
{
  printf("\nPlease enter patient's name (max 100 characters): ");
  scanf("%[^\n]s", name);
  while ((getchar()) != '\n');
}

return_code_t get_phone_number_input(char* phone_number)
{
  uint8_t tries = 0;
  do {
    printf("Please enter patient's phone number: ");
    scanf("%s", phone_number);
    while ((getchar()) != '\n');
    ++tries;
  } while (!is_valid_phone_number(phone_number) && tries != 3);

  if (tries == 3 && !is_valid_phone_number(phone_number))
  {
    printf("Too many invalid input, aborting...");
    return VALIDATION_FAILURE;
  }
  return SUCCESS;
}

return_code_t get_paid_input(char* ch)
{
  uint8_t tries = 0;
  do {
    printf("Please enter whether it's paid or not [y/n]: ");
    scanf("%c", ch);
    while ((getchar()) != '\n');
    ++tries;
  } while (!is_valid_paid(*ch) && tries != 3);

  if (tries == 3 && !is_valid_paid(*ch))
  {
    printf("Too many invalid input, aborting...\n\n");
    return VALIDATION_FAILURE;
  }
  return SUCCESS;
}

void try_to_write_buffer(event_t* event)
{
  return_code_t rc;
  do {
    pthread_mutex_lock(&lock);
    rc = write_buffer(buffer, event);
    pthread_mutex_unlock(&lock);
  } while (rc != SUCCESS);
}

void handle_add_option()
{
  return_code_t rc = SUCCESS;
  char name[NAME_SIZE] = "";
  uint16_t year_of_birth = 0;
  char phone_number[PHONE_NUMBER_SIZE] = "";
  char ch = '\0';

  get_name_input(name);
  rc = get_year_input(&year_of_birth);
  if (rc != SUCCESS) return;
  rc = get_phone_number_input(phone_number);
  if (rc != SUCCESS) return;

  if (cache.size != 0)
  {
    size_patient_pair_t pair = lookup_patient(phone_number);
    if (pair.second)
    {
      printf("Patient already exists!\n");
      return;
    }
  }
  rc = get_paid_input(&ch);
  if (rc != SUCCESS) return;

  return_code_patient_pair_t rc_patient_pair = create_patient(name, year_of_birth, phone_number, ch == 'y' ? true : false);
  rc = rc_patient_pair.first;
  if (rc != SUCCESS)
  {
    print_error(rc);
    return;
  }
  event_t add_event;
  add_event.type = ADD;
  add_event.patient = rc_patient_pair.second;
  try_to_write_buffer(&add_event);
}

void handle_remove_option()
{
  if (cache.size == 0)
  {
    printf("We don't have records yet...\n");
    return;
  }
  return_code_t rc = SUCCESS;
  char phone_number[PHONE_NUMBER_SIZE] = "";
  rc = get_phone_number_input(phone_number);
  if (rc != SUCCESS) return;

  size_patient_pair_t pair;
  if (cache.size != 0)
  {
    pair = lookup_patient(phone_number);
    if (pair.second == NULL)
    {
      printf("Patient doesn't exist!\n");
      return;
    }
  }
  event_t delete_event;
  delete_event.type = DELETE;
  delete_event.index = pair.first;
  delete_event.patient = pair.second;

  try_to_write_buffer(&delete_event);
}

void show_modify_options()
{
  printf("Please enter what would you like to modify - options:\n");
  printf(" -name: n\n");
  printf(" -year of birth: y\n");
  printf(" -phone number: p\n");
  printf(" -paid: o\n");
  printf("For example: yo\n");
}

void handle_modify_input(patient_t* current_patient, size_t modify_index)
{
  return_code_t rc = SUCCESS;
  char name[NAME_SIZE] = "";
  uint16_t year_of_birth = 0;
  char phone_number[PHONE_NUMBER_SIZE] = "";
  char ch = '\0';

  char options[4] = "";
  scanf("%s", options);
  while ((getchar()) != '\n');
  for (size_t i = 0; i < strlen(options) && options[i] != '\0'; ++i)
  {
    switch(options[i])
    {
      case 'n':
        printf("You've selected {name} change!\n");
        get_name_input(name);
        break;
      case 'y':
        printf("You've selected {year of birth} change!\n");
        rc = get_year_input(&year_of_birth);
        if (rc != SUCCESS) return;
        break;
      case 'p':
        printf("You've selected {phone number} change!\n");
        rc = get_phone_number_input(phone_number);
        if (rc != SUCCESS) return;
        break;
      case 'o':
        printf("You've selected {paid} change!\n");
        rc = get_paid_input(&ch);
        if (rc != SUCCESS) return;
        break;
      default:
        printf("Skipping invalid option: %c", options[i]);
    }
  }
  return_code_patient_pair_t rc_patient_pair = create_patient(
          empty(name) ? current_patient->name : name,
          year_of_birth == 0 ? current_patient->year_of_birth : year_of_birth,
          empty(phone_number) ? current_patient->phone_number : phone_number,
          ch == '\0' ? current_patient->paid : (ch == 'y' ? true : false)
  );
  if (rc_patient_pair.first != SUCCESS) {
    print_error(rc_patient_pair.first);
    return;
  }
  event_t modify_event;
  modify_event.type = MODIFY;
  modify_event.index = modify_index;
  modify_event.patient = rc_patient_pair.second;
  try_to_write_buffer(&modify_event);
}

size_patient_pair_t lookup_patient(const char* key)
{
  size_patient_pair_t pair;
  pair.second = NULL;
  pthread_mutex_lock(&lock);
  for (size_t i = 0; i < cache.size; ++i)
  {
    if (strcmp(cache.data[i].phone_number, key) == 0)
    {
      pair.first = i;
      pair.second = &cache.data[i];
      printf("Found patient at index %ld\n", pair.first);
      pthread_mutex_unlock(&lock);
      break;
    }
  }
  pthread_mutex_unlock(&lock);
  return pair;
}

void handle_modify_option()
{
  if (cache.size == 0)
  {
    printf("Cache is empty, can't modify!\n");
    return;
  }
  char key[PHONE_NUMBER_SIZE];
  return_code_t rc;
  rc = get_phone_number_input(key);
  if (rc != SUCCESS) return;

  size_patient_pair_t pair = lookup_patient(key);
  if (!pair.second)
  {
    printf("Patient not found!");
    return;
  }
  show_modify_options();
  handle_modify_input(pair.second, pair.first);
}

void handle_show_option()
{
  printf("Please see all the records below:\n\n");
  pthread_mutex_lock(&lock);
  for (size_t i = 0; i < cache.size; ++i)
  {
    print_patient(&cache.data[i]);
  }
  printf("\n");
  pthread_mutex_unlock(&lock);
}

void handle_invalid_input()
{
  printf("Invalid input...");
}

void handle_exit_option()
{
  event_t exit_event;
  exit_event.type = EXIT;
  exit_event.patient = NULL;
  try_to_write_buffer(&exit_event);
}

bool handle_user_input()
{
  char option = '\0';
  scanf("%c", &option);
  while ((getchar()) != '\n');
  switch (option) {
    case 'a':
      handle_add_option();
      break;
    case 'm':
      handle_modify_option();
      break;
    case 'r':
      handle_remove_option();
      break;
    case 's':
      handle_show_option();
      break;
    case 'e':
      handle_exit_option();
      return false;
    case 'h':
      printf("\n\n");
      show_command_options();
      break;
    default:
      handle_invalid_input();
  }
  return true;
}

void* main_handler()
{
  pthread_mutex_lock(&lock);
  //printf("Initializing cache...\n");
  cache.size = 0;
  cache.capacity = INITIAL_CACHE_SIZE;
  //printf("Initializing buffer...\n");
  buffer = initialize_buffer();
  pthread_mutex_unlock(&lock);

  bool running = true;
  printf("Welcome to our London Data Center!\n\n");

  while(running)
  {
    show_command_options();
    running = handle_user_input();
  }
  return NULL;
}

void wait_for_buffer_ready()
{
  bool running = true;
  while (running)
  {
    //printf("Waiting for buffer...\n");
    if (buffer->data != NULL)
    {
      //printf("Buffer is ready...\n");
      return;
    }
    sleep(1);
  }
}

void try_to_read_buffer(event_t* events, size_t i)
{
  event_t event;
  pthread_mutex_lock(&lock);
  event = read_buffer(buffer);
  pthread_mutex_unlock(&lock);
  events[i] = event;
}

void process_add_event(event_t* event)
{
  pthread_mutex_lock(&lock);
  add_patient(&cache, event->patient);
  pthread_mutex_unlock(&lock);
}

void process_modify_event(event_t* event)
{
  pthread_mutex_lock(&lock);
  modify_patient(&cache, event->patient, event->index);
  pthread_mutex_unlock(&lock);
}
void process_delete_event(event_t* event)
{
  pthread_mutex_lock(&lock);
  remove_patient(&cache, event->index);
  pthread_mutex_unlock(&lock);
}

void on_exit_callback()
{
  FILE* fptr = open_file("wb");
  if (fptr != NULL) {
    pthread_mutex_lock(&lock);
    write_file(fptr, &cache);
    pthread_mutex_unlock(&lock);
    close_file(fptr);
  }
  deallocate_buffer(buffer);
}

bool process_events(event_t* events, size_t read_count)
{
  for (size_t i = 0; i < read_count; ++i) {
    if (events[i].type != EXIT)
    {
      printf("Processing event: event.type %d event.index %ld event.patient: ", events[i].type, events[i].index);
      print_patient(events[i].patient);
    }

    switch(events[i].type) {
      case ADD:
        process_add_event(&events[i]);
        break;
      case MODIFY:
        process_modify_event(&events[i]);
        break;
      case DELETE:
        process_delete_event(&events[i]);
        break;
      case EXIT:
        on_exit_callback();
        return false;
      case INVALID:
        printf("Read an invalid event\n");
        break;
    }
  }
  return true;
}

bool poll()
{
  size_t buff_size = buffer->size;
  event_t events[CIRCULAR_BUFFER_SIZE];
  bool result = true;
  if (buff_size > 0) {
    for (size_t i = 0; i < buff_size; ++i) {
      try_to_read_buffer(events, i);
    }
    result = process_events(events, buff_size);
  }
  return result;
}

void* reflex_handler()
{
  wait_for_buffer_ready();
  char option[3] = "rb";
  FILE* fptr = open_file(option);
  if (fptr != NULL)
  {
    read_file(fptr, &cache);
    close_file(fptr);
  }
  bool running = true;
  while (running)
  {
    running = poll();
  }
  return NULL;
}

int run()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  current_year = tm.tm_year + 1900;

  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS] = {MAIN_THREAD_ID, REFLEX_THREAD_ID};

  if (pthread_mutex_init(&lock, NULL) != 0)
  {
    printf("mutex init failed\n");
    return 1;
  }


  int rc;
  for (int i = 0; i < NUM_THREADS; ++i) {
    void* fn = thread_ids[i] == MAIN_THREAD_ID ? main_handler : reflex_handler;
    rc = pthread_create(&threads[i], NULL, fn, NULL);
    if (rc) {
      printf("Error:unable to create thread, %d\n", rc);
      return 1;
    }
  }

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  pthread_mutex_destroy(&lock);
  return 0;
}


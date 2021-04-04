//
// Created by molna on 2021. 04. 02..
//
#pragma once

#include "lib/Event.h"
#include "io/FileHandler.h"
#include <time.h>
#include "lib/Cache.h"


//globals
pthread_mutex_t lock;
circular_buffer_t* buffer; //shared
uint16_t current_year;
cache_t cache; //shared

ALLOCATE(circular_buffer_t);
DEALLOCATE(circular_buffer_t);

circular_buffer_t* initialize_buffer();
void deallocate_buffer(circular_buffer_t* buffer);

void wait_for_buffer_ready();
void on_exit_callback();

void* main_handler();
void* reflex_handler();

void exit_app();
int run();
bool poll();
bool process_events(event_t* events, size_t read_count);
void process_add_event(event_t* event);
void process_modify_event(event_t* event);
void process_delete_event(event_t* event);

void show_command_options();
void show_modify_options();
bool handle_user_input();
//user options
void handle_add_option();
void handle_modify_option();
void handle_modify_input(patient_t* current_patient, size_t modify_index);
void handle_remove_option();
void handle_show_option();
void handle_invalid_input();
void handle_exit_option();

void try_to_write_buffer(event_t* event);
void try_to_read_buffer(event_t* events, size_t i);
size_patient_pair_t lookup_patient(const char* key);

//validation
return_code_t get_year_input(uint16_t* year_of_birth);
return_code_t get_name_input(char* name);
return_code_t get_phone_number_input(char* phone_number);
return_code_t get_paid_input(char* ch);


//reflex interface



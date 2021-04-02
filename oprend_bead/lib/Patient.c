#include "Patient.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ALLOCATE_IMPL(patient_t);
DEALLOCATE_IMPL(patient_t);

char* hash_key(patient_t* patient)
{
  return patient->phone_number;
}

bool empty(char* str)
{
  return (strlen(str) == 0);
}

return_code_t is_valid(const char* name, const char* phone_number)
{
  if (name && phone_number)
  {
    return SUCCESS;
  }
  return VALIDATION_FAILURE;
}

bool is_valid_phone_number(const char* phone_number)
{
  return (phone_number && (strlen(phone_number) < PHONE_NUMBER_SIZE)) ? true : false;
}

bool is_valid_year(uint16_t current_year, uint16_t input)
{
  return (1900 < input && input <= current_year);
}

bool is_valid_paid(char paid)
{
  return paid == 'y' || paid == 'n';
}

return_code_patient_pair_t create_patient(const char* name, uint16_t year_of_birth, const char* phone_number, bool paid)
{
  patient_t* patient = allocate_patient_t();
  return_code_patient_pair_t rc_patient;
  return_code_t* rc = &rc_patient.first;
  *rc = SUCCESS;
  rc_patient.second = patient;
  if (!patient)
  {
    *rc = ALLOCATION_FAILURE;
    return rc_patient;
  }
  *rc = is_valid(name, phone_number);
  if (*rc != SUCCESS) {
    return rc_patient;
  }
  strncpy(patient->name, name, strlen(name));
  patient->year_of_birth = year_of_birth;
  strncpy(patient->phone_number, phone_number, PHONE_NUMBER_SIZE);
  patient->paid = paid;
  if (!strcmp(patient->name, name) || !strcmp(patient->phone_number, phone_number))
  {
    return rc_patient;
  }
  *rc = COPY_FAILURE;
  return rc_patient;
}

return_code_t copy_chars(char* dest, const char* from, bool re_alloc)
{
  if (re_alloc)
  {
    dest = (char*)realloc(dest, strlen(from) + CHAR_NULL);
    if (!dest) {
      return ALLOCATION_FAILURE;
    }
  }
  memset(dest, 0, strlen(from));
  strncpy(dest, from, strlen(from));
  return SUCCESS;
}

void modify_patient_name(patient_t* patient, const char* name)
{
  return_code_t rc = copy_chars(patient->name, name, true);
  if (rc != SUCCESS) {
    printf("Failed to modify field {name} error: ");
    print_error(rc);
  }
}

void modify_patient_year_of_birth(patient_t* patient, uint16_t year_of_birth)
{
  patient->year_of_birth = year_of_birth;
}

void modify_patient_phone_number(patient_t* patient, const char* phone_number)
{
  return_code_t rc = is_valid_phone_number(phone_number);
  if (rc == SUCCESS)
  {
    copy_chars(patient->phone_number, phone_number, false);
  }
  else
  {
    printf("Failed to modify field {phone_number} error: ");
    print_error(rc);
  }
}
void modify_patient_paid(patient_t* patient, bool paid)
{
  patient->paid = paid;
}

static const char* paid_str = "paid";
static const char* not_paid = "not paid";

void print_patient(patient_t* patient)
{
  printf("%s %d %s %s\n",
         patient->name,
         patient->year_of_birth,
         patient->phone_number,
         (patient->paid ? paid_str : not_paid));
}
//
// Created by molna on 2021. 03. 31..
//
#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "../types/Enums.h"
#include "../util/Pair.H"
#include "../types/Defines.h"
#include <stdlib.h>

typedef struct Patient {
    char name[100];
    uint16_t year_of_birth;
    char phone_number[PHONE_NUMBER_SIZE];
    bool paid;
    bool vaccinated;
} patient_t;

Pair(return_code_t, patient_t, return_code_, patient);
Pair(size_t, patient_t, size_, patient);
ALLOCATE(patient_t);
DEALLOCATE(patient_t);

return_code_t is_valid(const char* name, const char* phone_number);
bool is_valid_phone_number(const char* phone_number);
bool is_valid_year(uint16_t current_year, uint16_t input);
bool is_valid_paid(char paid);

return_code_patient_pair_t create_patient(const char* name,
                                          uint16_t year_of_birth,
                                          const char* phone_number,
                                          bool paid);

return_code_t copy_chars(char* dest, const char* from, bool re_alloc);
void modify_patient_name(patient_t* patient, const char* name);
void modify_patient_year_of_birth(patient_t* patient, uint16_t year_of_birth);
void modify_patient_phone_number(patient_t* patient, const char* phone_number);
void modify_patient_paid(patient_t* patient, bool paid);
char* hash_key(patient_t* patient);

bool empty(char* str);


void print_patient(patient_t* patient);


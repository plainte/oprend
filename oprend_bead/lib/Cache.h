//
// Created by molna on 2021. 04. 02..
//
#pragma once

#include "Patient.h"
#include <stdlib.h>

typedef struct Cache {
    size_t size;
    size_t capacity;
    size_t waiting_list_hint;
    patient_t data[INITIAL_CACHE_SIZE];
} cache_t;


void add_patient(cache_t* cache, patient_t* patient, bool log);
void modify_patient(cache_t* cache, patient_t* patient, size_t index);
void remove_patient(cache_t* cache, size_t index);

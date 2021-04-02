//
// Created by molna on 2021. 04. 02..
//
#pragma once

#include "Enums.h"


#define PHONE_NUMBER_SIZE 12
#define NAME_SIZE 100
#define INITIAL_CACHE_SIZE 1000
#define CIRCULAR_BUFFER_SIZE 20
#define CACHE_MULTIPLIER 2
#define CHAR_NULL 1
#define MAIN_THREAD_ID 1
#define REFLEX_THREAD_ID 2
#define NUM_THREADS 2


#define ALLOCATE(T) \
  T* allocate_##T();

#define ALLOCATE_IMPL(T) \
  T* allocate_##T() {\
    T* t = (T*)malloc(sizeof(T)); \
    return t;              \
  }

#define DEALLOCATE(T) \
  void deallocate_##T(T* t);

#define DEALLOCATE_IMPL(T) \
  void deallocate_##T(T* t) { \
    if (t) free(t); \
  }

void print_error(return_code_t rc);
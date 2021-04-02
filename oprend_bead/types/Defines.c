//
// Created by molna on 2021. 04. 02..
//
#include "Defines.h"
#include <stdio.h>

static const char* allocation_failure = "allocation failure";
static const char* validation_failure = "validation failure";
static const char* copy_failure = "copy failure";
static const char* cant_open_file = "cant open file";
static const char* cant_close_file = "cant close file";
static const char* cant_write_file = "cant write file";
static const char* buffer_is_full = "buffer is full";
static const char* buffer_is_empty = "buffer is empty";
static const char* missing_capacity = "missing capacity";
static const char* invalid_capacity = "invalid capacity";
static const char* invalid_phone_number= "invalid phone number";
static const char* success = "success";

void print_error(return_code_t rc) {
  switch (rc) {
    case ALLOCATION_FAILURE:
      printf("%s\n", allocation_failure);
      break;
    case VALIDATION_FAILURE:
      printf("%s\n", validation_failure);
      break;
    case COPY_FAILURE:
      printf("%s\n", copy_failure);
      break;
    case CANT_OPEN_FILE:
      printf("%s\n", cant_open_file);
      break;
    case CANT_CLOSE_FILE:
      printf("%s\n", cant_close_file);
      break;
    case CANT_WRITE_FILE:
      printf("%s\n", cant_write_file);
      break;
    case BUFFER_IS_FULL:
      printf("%s\n", buffer_is_full);
      break;
    case BUFFER_IS_EMPTY:
      printf("%s\n", buffer_is_empty);
      break;
    case MISSING_CAPACITY:
      printf("%s\n", missing_capacity);
      break;
    case INVALID_CAPACITY:
      printf("%s\n", invalid_capacity);
      break;
    case INVALID_PHONE_NUMBER:
      printf("%s\n", invalid_phone_number);
      break;
    case SUCCESS:
    default:
      printf("%s\n", success);
  }
}

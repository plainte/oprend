//
// Created by molna on 2021. 04. 02..
//
#pragma once

#include <stdlib.h>


#define DEF_CIRCULAR_BUFFER(type) \
  typedef struct CircularBuffer { \
    type* data;               \
    size_t reader;              \
    size_t writer;              \
    size_t size;                \
    size_t capacity;            \
} circular_buffer_t;

#define BUFFER_ALLOCATORS(T) \
  return_code_t allocate_data_##T(circular_buffer_t* buffer); \
  void deallocate_data_##T(circular_buffer_t* buffer);

#define BUFFER_ALLOCATORS_IMPL(T) \
  return_code_t allocate_data_##T(circular_buffer_t* buffer) { \
    if(buffer->capacity == 0) {    \
      return MISSING_CAPACITY;            \
    }                              \
    buffer->data = (T*)malloc(sizeof(T)*buffer->capacity);    \
    return buffer->data ? SUCCESS : ALLOCATION_FAILURE; \
  }                             \
  void deallocate_data_##T(circular_buffer_t* buffer) {        \
    if (buffer->data) {         \
      free(buffer->data);                           \
    } \
  }

#define CIRCULAR_BUFFER_DEFAULTS(T) \
  return_code_t set_circular_buffer_defaults_##T(circular_buffer_t* buffer, size_t capacity);

#define CIRCULAR_BUFFER_DEFAULTS_IMPL(T) \
  return_code_t set_circular_buffer_defaults_##T(circular_buffer_t* buffer, size_t capacity) { \
    if (capacity < 1) {                \
      return INVALID_CAPACITY; \
    }                                  \
    buffer->reader = 0; \
    buffer->writer = 0;                \
    buffer->size = 0; \
    buffer->capacity = capacity;            \
    return SUCCESS;                            \
  }

#define WRITE_BUFFER(T) \
  return_code_t write_buffer(circular_buffer_t* buffer, T* item);

#define WRITE_BUFFER_IMPL(T) \
  return_code_t write_buffer(circular_buffer_t* buffer, T* item) { \
    if (buffer->size == buffer->capacity) {                      \
      return BUFFER_IS_FULL; \
    }                           \
    buffer->data[buffer->writer] = *item;                             \
    if (++buffer->writer == buffer->capacity) buffer->writer = 0; \
    ++buffer->size;               \
    return SUCCESS; \
}

#define READ_BUFFER(T) \
  T read_buffer(circular_buffer_t* buffer);

#define READ_BUFFER_IMPL(T) \
  T read_buffer(circular_buffer_t* buffer) { \
    T item;                 \
    item.type = INVALID;        \
    \
    if (buffer->size == 0) {                      \
      return item; \
    }                       \
    item = buffer->data[buffer->reader];     \
    if (++buffer->reader == buffer->capacity) buffer->reader = 0;        \
    --buffer->size;               \
    return item; \
}

//
// Created by molna on 2021. 04. 02..
//
#include "Cache.h"
#include <stdio.h>

void add_patient(cache_t* cache, patient_t* patient, bool log)
{
  if (cache->size + 1 <= cache->capacity)
  {
    cache->data[cache->size] = *patient;
    if (log)
    {
      printf("\nAdded patient: ");
      print_patient(&cache->data[cache->size]);
    }
    ++cache->size;
  }
  else
  {
    printf("\nCache is full, dropping patient: ");
    print_patient(patient);
  }
}

void modify_patient(cache_t* cache, patient_t* patient, size_t index)
{
  if (cache->size <= index)
  {
    printf("\nERROR: index above cache size");
  }
  else
  {
    printf("\nModifying patient: ");
    print_patient(&cache->data[index]);
    cache->data[index] = *patient;
    printf("\nModified patient to: ");
    print_patient(&cache->data[index]);
  }
}

void remove_patient(cache_t* cache, size_t index)
{
  if (cache->size == 0)
  {
    printf("\nCache is empty can't remove patient");
  }
  else
  {
    //printf("\nCurrent cache size: %zu", cache->size);
    printf("\nRemoving patient: ");
    print_patient(&cache->data[index]);
    for (size_t i = index; i < cache->size - 1; ++i)
    {
      cache->data[index] = cache->data[index + 1];
    }
    --cache->size;
    //printf("New cache size: %zu\n", cache->size);
  }

}


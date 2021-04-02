//
// Created by molna on 2021. 04. 01..
//

#include "FileHandler.h"
#include <stdlib.h>

FILE* open_file(char* option)
{
  char file_name[15] = "./patients.bin";
  FILE* fptr = fopen(file_name, option);
  return fptr;
}


void close_file(FILE* fptr)
{
  if (fptr != NULL)
  {
    int result = fclose(fptr);
    if (result != 0)
    {
      print_error(CANT_CLOSE_FILE);
      exit(-1);
    }
  }
}

void read_file(FILE* fptr, cache_t* cache)
{
  if (cache->size != 0)
  {
    printf("ERROR: cache size not zero\n");
    exit(-1);
  }
  else
  {
    if (fptr != NULL)
    {
      patient_t patient;
      //printf("Cache details: %zu %zu", cache->size, cache->capacity);
      while(cache->size != cache->capacity && fread(&patient, sizeof(patient_t), 1, fptr))
      {
        //printf("Read patient: ");
        add_patient(cache, &patient);
        print_patient(&patient);
      }
    }
  }
  //printf("Cache size: %zu\n", cache->size);
}

void write_file(FILE* fptr, cache_t* cache)
{
  if (fptr != NULL) {
    for (size_t i = 0; i < cache->size; ++i) {
      fwrite (&cache->data[i], sizeof(patient_t), 1, fptr);
    }
  }
}

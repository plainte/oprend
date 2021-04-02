  //
// Created by molna on 2021. 04. 01..
//
#pragma once

#include "../types/Enums.h"
#include "../lib/Patient.h"
#include "../lib/Cache.h"
#include <stdio.h>

FILE* open_file(char* option);
void close_file(FILE* file_handler);
void read_file(FILE* file_handler, cache_t* cache);
void write_file(FILE* file_handler, cache_t* cache);

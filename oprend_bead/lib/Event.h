//
// Created by molna on 2021. 04. 02..
//
#pragma once

#include "../types/Enums.h"
#include "../util/CircularBuffer.h"
#include "Patient.h"

typedef struct Event {
    event_type_t type;
    size_t index;
    patient_t* patient;
} event_t;

DEF_CIRCULAR_BUFFER(event_t);
CIRCULAR_BUFFER_DEFAULTS(event_t);
BUFFER_ALLOCATORS(event_t);
WRITE_BUFFER(event_t);
READ_BUFFER(event_t);
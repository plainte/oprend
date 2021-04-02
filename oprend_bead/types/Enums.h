//
// Created by molna on 2021. 04. 01..
//
#pragma once

typedef enum ReturnCode {
    SUCCESS,
    ALLOCATION_FAILURE,
    VALIDATION_FAILURE,
    COPY_FAILURE,
    CANT_OPEN_FILE,
    CANT_CLOSE_FILE,
    CANT_WRITE_FILE,
    BUFFER_IS_FULL,
    MISSING_CAPACITY,
    INVALID_CAPACITY,
    BUFFER_IS_EMPTY,
    INVALID_PHONE_NUMBER
} return_code_t;

typedef enum EventType {
    INVALID,
    ADD,
    MODIFY,
    DELETE,
    EXIT
} event_type_t;

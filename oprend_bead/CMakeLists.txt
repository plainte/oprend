cmake_minimum_required(VERSION 3.16)
project(oprend_bead C)

set(CMAKE_C_STANDARD 11)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pthread ")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(oprend_bead main.c lib/Patient.h lib/Patient.c types/Enums.h io/FileHandler.h io/FileHandler.c
        lib/Event.h util/CircularBuffer.h util/CircularBuffer.c util/Pair.H types/Defines.h App.h App.c lib/Event.c
        types/Defines.c lib/Cache.h lib/Cache.c)
//
// Created by molna on 2021. 04. 02..
//
#pragma once

#define Pair(T1, T2, T1name, T2name) \
  typedef struct T1name##T2name { \
    T1 first;           \
    T2* second;         \
  } T1name##T2name##_pair_t;





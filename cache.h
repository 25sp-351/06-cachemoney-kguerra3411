#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>

#define MAX_MEMOIZED 150000
#define ARRAY_SIZE (MAX_MEMOIZED + 1)

typedef char *(*char_func_ptr)(int param);

extern char_func_ptr _original_provider;
extern char *_memoization_data[ARRAY_SIZE];

char *cache_func(int n);

char_func_ptr init_cache(char_func_ptr real_provider);

#endif
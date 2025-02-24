#include "cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMOIZED 150000
#define ARRAY_SIZE (MAX_MEMOIZED + 1)
#define NO_VALUE_YET NULL

static char* _memoization_data[ARRAY_SIZE];
static char_func_ptr _original_provider;

char* cache_func(int n) {
    printf(__FILE__ ":%2d   cache_func(%d) called\n", __LINE__, n);

    if (n > MAX_MEMOIZED) {
        printf(__FILE__ ":%2d   Value %d is temporarily too large for cache, using original provider.\n", __LINE__, n);
        return (*_original_provider)(n);
    }

    if (_memoization_data[n] == NO_VALUE_YET) {
        printf(__FILE__ ":%2d   Value %d not yet in cache\n", __LINE__, n);
        _memoization_data[n] = _strdup((*_original_provider)(n));
    } else {
        printf(__FILE__ ":%2d   Value %d found in cache\n", __LINE__, n);
    }

    return _memoization_data[n];
}

char_func_ptr init_cache(char_func_ptr real_provider) {
    for (int ix = 0; ix < ARRAY_SIZE; ix++) {
        _memoization_data[ix] = NO_VALUE_YET;
    }
    _original_provider = real_provider;
    return cache_func;
}

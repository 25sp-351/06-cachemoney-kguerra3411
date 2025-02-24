#include <stdio.h>
#include "cache.h"
#include "num_to_words.h"


// DISCLAIMER: I am so confused right now. I tried using the loaded cache github and it wasnt working out for me both literally and figurativelty 
// could not get it figured out through set up I think i have things separated but im not 100% so i'll keep pushing 

char* memoize(int num) {
    return cache_func(num);
}

int main() {
    char_func_ptr function_ptr = init_cache(numToWords);

    int input_num;

    while (1) {
        if (scanf_s("%d", &input_num) != 1) {
            printf("main.c:%2d   Error: Characters are not allowed. Please enter a valid number.\n", __LINE__);
            
            while (getchar() != '\n');  
            continue;  
        }        
        if (input_num < 0) {
            printf("main.c:%2d   Error: Negative numbers are not allowed. Please enter a valid number.\n", __LINE__);
            continue;
        }

        int dollars = input_num / 100;
        int cents = input_num % 100;

        printf("main.c:%2d   Calling function_ptr(%d)\n", __LINE__, dollars);
        char* dollar_str = function_ptr(dollars);

        printf("main.c:%2d   Calling function_ptr(%d)\n", __LINE__, cents);
        char* cent_str = function_ptr(cents);

        printf("main.c:%2d  %d = %s dollars and %s cents\n", __LINE__, input_num, dollar_str, cent_str);
    }

    return 0;
}

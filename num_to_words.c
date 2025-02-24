#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num_to_words.h"
#include "cache.h"

char* numToWords(int num) {
    
    char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    char word_progress[200] = "";

    if (num < 0) {
        strcat_s(word_progress, sizeof(word_progress), "negative ");
        num = -num;
    }
    if (num == 0) {
        strcpy_s(word_progress, sizeof(word_progress), "zero");
    } else {
        if (num / 1000000000 > 0) {
            strcat_s(word_progress, sizeof(word_progress), numToWords(num / 1000000000));
            strcat_s(word_progress, sizeof(word_progress), " billion ");
            num %= 1000000000;
        }
        if ( num / 1000000 > 0) {
            strcat_s(word_progress, sizeof(word_progress), numToWords(num / 1000000));
            strcat_s(word_progress, sizeof(word_progress), " million ");
            num %= 1000000;
        }
        if (num / 1000 > 0) {
            strcat_s(word_progress, sizeof(word_progress), numToWords(num / 1000));
            strcat_s(word_progress, sizeof(word_progress), " thousand ");
            num %= 1000;
        }
        if (num / 100 > 0) {
            strcat_s(word_progress, sizeof(word_progress), numToWords(num / 100));
            strcat_s(word_progress, sizeof(word_progress), " hundred ");
            num %= 100;
        }
        if (num >= 10 && num < 20) {
            strcat_s(word_progress, sizeof(word_progress), teens[num - 10]);
        } else {
            if (num / 10 > 0) {
                strcat_s(word_progress, sizeof(word_progress), tens[num / 10]);
                strcat_s(word_progress, sizeof(word_progress), " ");
            }
            if (num % 10 > 0) {
                strcat_s(word_progress, sizeof(word_progress), ones[num % 10]);
            }
        }
    }

    char *result = malloc(strlen(word_progress) + 1);
    if (result != NULL) {
        strcpy_s(result, strlen(word_progress) + 1, word_progress);
    }
    return result;
}
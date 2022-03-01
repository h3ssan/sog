#include "src/headers/validation.h"

int isnumber(char *value) {
    unsigned int value_len = strlen(value);
    unsigned char isDigit = 1;

    for (int i = 0; i < value_len; i++) {
        if (!isdigit(value[i])) {
            isDigit = 0;
            break;
        }
    }

    return isDigit == 1;
}

int ispositive(unsigned long long value) {
    return value >= 0;
}
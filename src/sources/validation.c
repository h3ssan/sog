#include "src/headers/validation.h"

int isnumber(char *value) {
    unsigned int value_len = strlen(value);
    unsigned char isDigit = 1;

    unsigned int i;
    for (i = 0; i < value_len; i++) {
        if (!isdigit(value[i])) {
            isDigit = 0;
            break;
        }
    }

    return isDigit == 1;
}

void check_valid_options(int argc, char *argv[], const char *VALID_OPTIONS[]) {
    unsigned int i, j;
    for (i = 1; i < argc; i++) {
        unsigned char argument_found = 0;
        for (j = 0; j < 6; j++) {
            if (strcmp(argv[i], VALID_OPTIONS[j]) == 0) {
                argument_found = 1;

                if (j > 1) {
                    if (i+1 < argc) {
                        i++;
                    } else {
                        printf("Value for %s is required.%c", argv[i], 10);
                        printf("Try '%s --help' for more information.%c", argv[0], 10);
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }

        if (argument_found == 0) {
            printf("option %s is unknown.%c", argv[i], 10);
            printf("Try '%s --help' for more information.%c", argv[0], 10);
            exit(EXIT_FAILURE);
        }
    }
}
#include "main.h"

int main(int argc, char *argv[]) {
    // Use current time as seed for random generators
    srand(time(0));

    check_valid_options(argc, argv);

    return EXIT_SUCCESS;
}

void check_valid_options(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        unsigned char argument_found = 0;
        for (int j = 0; j < 6; j++) {
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

void generate_v3_address() {
    for (int j = 0; j < count; ++j) {
        for (int i = 0; i < 55; i++) {
            int num = (rand() % (MAX_LEN - MIN_LEN + 1)) + MIN_LEN;

            printf("%c", ALPHABETS[num]);
        }
        printf("d.onion%c", 10);
    }
}

void generate_v2_address() {
    printf("Kindly use V3 addresses, because of the deprecation of onion V2 addresses.%c%c", 10, 10);

    for (int j = 0; j < count; ++j) {
        for (int i = 0; i < 15; i++) {
            int num = (rand() % (MAX_LEN - MIN_LEN + 1)) + MIN_LEN;

            printf("%c", ALPHABETS[num]);
        }
        printf(".onion%c", 10);
    }
}
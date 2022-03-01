#include "src/headers/main.h"

int main(int argc, char *argv[]) {
    // Use current time as seed for random generators
    srand(time(0));

    check_valid_options(argc, argv);
    parse_arguments(argc, argv);

    if (onion_address_version == 3) {
        generate_v3_address();
    } else {
        fprintf(stderr, "Kindly use V3 addresses, because of the deprecation of onion V2 addresses.%c%c", 10, 10);
        generate_v2_address();
    }

    return EXIT_SUCCESS;
}

void show_menu(char *app_name) {
    printf("Usage: %s [options ...]", app_name);
    printf("Options:\n\t");
    printf("--help, -h\t\tShow this help menu.\n\t");
    printf("--count, -c n \t\tApp generates nth onions.\n\t");
    printf("--version, -v 2|3 \tOnion address version, can be 2 or 3.\n");
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

void argument_value_error(char *app_name, char *option) {
    printf("Value for %s is not valid.%c", option, 10);
    printf("Try '%s --help' for more information.%c", app_name, 10);
    exit(EXIT_FAILURE);
}

void parse_arguments(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        char *argument = argv[i];
        char *value = argv[i+1];

        if ((strcmp(argument, "-h") == 0) || (strcmp(argument, "--help") == 0)) {
            show_menu(argv[0]);
            exit(EXIT_SUCCESS);
        } else if ((strcmp(argument, "-v") == 0) || (strcmp(argument, "--version") == 0)) {
            if ((strcmp(value, "2") == 0) || (strcmp(value, "3") == 0)) {
                onion_address_version = atoi(value);
            } else {
                argument_value_error(argv[0], argument);
            }
        } else if ((strcmp(argument, "-c") == 0) || (strcmp(argument, "--count") == 0)) {
            if (isnumber(value)) {
                count = atoll(value);
            } else {
                argument_value_error(argv[0], argument);
            }
        }

        i++;
    }
}

void generate_v3_address() {
    if (count > 0) {
        for (int j = 0; j < count; ++j) {
            generate_v3_internal();
        }
    } else {
        while (count <= 0) {
            generate_v3_internal();
        }
    }
}

void generate_v3_internal() {
    for (int i = 0; i < 55; i++) {
        int num = (rand() % (MAX_LEN - MIN_LEN + 1)) + MIN_LEN;

        printf("%c", ALPHABETS[num]);
    }
    printf("d.onion%c", 10);
}

void generate_v2_address() {
    if (count > 0) {
        for (int j = 0; j < count; ++j) {
            generate_v2_internal();
        }
    } else {
        while (count <= 0) {
            generate_v2_internal();
        }
    }
}

void generate_v2_internal() {
    for (int i = 0; i < 15; i++) {
        int num = (rand() % (MAX_LEN - MIN_LEN + 1)) + MIN_LEN;

        printf("%c", ALPHABETS[num]);
    }
    printf(".onion%c", 10);
}
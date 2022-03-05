#include "sog/main.h"

int main(int argc, char *argv[]) {
    /* Use current time as seed for random generators */
    srand(time(0));

    check_valid_options(argc, argv, VALID_OPTIONS);
    parse_arguments(argc, argv);

    generate_address(onion_address_version);

    return EXIT_SUCCESS;
}

void show_menu(char *app_name) {
    printf("Version: %s%c", APP_VERSION, 10);
    printf("Usage: %s [options ...]\n", app_name);
    printf("Options:\n\t");
    printf("--count, -c [0-9]+ \tGenerate n many addresses, 0 = unlimited.\n\t");
    printf("--help, -h\t\tShow this help menu.\n\t");
    printf("--version, -v (2|3) \tAddress version, can be 2 or 3.\n");
}

void argument_value_error(char *app_name, char *option) {
    printf("Value for %s is not valid.%c", option, 10);
    printf("Try '%s --help' for more information.%c", app_name, 10);
    exit(EXIT_FAILURE);
}

void parse_arguments(int argc, char *argv[]) {
    unsigned int i;
    for (i = 1; i < argc; ++i) {
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
                count = atol(value);
            } else {
                argument_value_error(argv[0], argument);
            }
        }

        i++;
    }
}

void generation(unsigned int address_len, char *address_ends) {
    unsigned int i, num;

    for (i = 0; i < address_len; i++) {
        num = (rand() % (MAX_LEN - MIN_LEN + 1)) + MIN_LEN;

        printf("%c", ALPHABETS[num]);
    }
    printf("%s%c", address_ends, 10);
}

void generate_address(unsigned char address_version) {
    unsigned int i, address_len;
    char *address_ends;

    if (address_version == 3) {
        address_len = 55;
        address_ends = "d.onion";
    } else {
        address_len = 15;
        address_ends = ".onion";

        fprintf(stderr, "Kindly use V3 addresses, because of the deprecation of onion V2 addresses.%c%c", 10, 10);
    }

    if (count == 0)
        while (count == 0)
            generation(address_len, address_ends);
    else
        for (i = 0; i < count; i++)
            generation(address_len, address_ends);
}
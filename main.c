#include "main.h"

int main(int argc, char *argv[]) {
    // Use current time as seed for random generators
    srand(time(0));

    generate_v3_address(1);

    return EXIT_SUCCESS;
}

void generate_v3_address(unsigned int count) {
    for (int j = 0; j < count; ++j) {
        for (int i = 0; i < 55; i++) {
            int num = (rand() % (MAX_LEN - MIN_LEN + 1)) + MIN_LEN;

            printf("%c", ALPHABETS[num]);
        }
        printf("d.onion%c", 10);
    }
}

void generate_v2_address(unsigned int count) {
    printf("Kindly use V3 addresses, because of the deprecation of onion V2 addresses.%c%c", 10, 10);

    for (int j = 0; j < count; ++j) {
        for (int i = 0; i < 15; i++) {
            int num = (rand() % (MAX_LEN - MIN_LEN + 1)) + MIN_LEN;

            printf("%c", ALPHABETS[num]);
        }
        printf(".onion%c", 10);
    }
}
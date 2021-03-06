#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "validation.h"

const char *APP_VERSION = "V2022-03-05";
const char *VALID_OPTIONS[6] = {"-h", "--help", "-v", "--version", "-c", "--count"};
const unsigned char ALPHABETS[36] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                                      'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                      'o', 'p', 'q', 'r', 's', 't', 'u',
                                      'v', 'w', 'x', 'y', 'z', '0', '1',
                                      '2', '3', '4', '5', '6', '7', '8',
                                      '9' };
const unsigned char MIN_LEN = 0;
const unsigned char MAX_LEN = 35;

unsigned char onion_address_version = 3;
unsigned long long count = 1;

void argument_value_error(char *app_name, char *option);
void parse_arguments(int argc, char *argv[]);
void generate_address(unsigned char address_version);
void generation(unsigned int address_len, char *address_ends);

#endif /* MAIN_H */

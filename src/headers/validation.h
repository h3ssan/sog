#ifndef VALIDATION_H
#define VALIDATION_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isnumber(char *value);
void check_valid_options(int argc, char *argv[], const char *VALID_OPTIONS[]);

#endif /* VALIDATION_H */

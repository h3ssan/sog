#ifndef VALIDATION_H
#define VALIDATION_H

#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "stdio.h"

#include <src/headers/main.h>

int isnumber(char *value);
void check_valid_options(int argc, char *argv[]);

#endif //VALIDATION_H

#ifndef MAIN_H
#define MAIN_H

#include "stdlib.h"
#include "stdio.h"
#include <time.h>

const unsigned char ALPHABETS[36] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                                      'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                      'o', 'p', 'q', 'r', 's', 't', 'u',
                                      'v', 'w', 'x', 'y', 'z', '0', '1',
                                      '2', '3', '4', '5', '6', '7', '8',
                                      '9' };
const unsigned char MIN_LEN = 0;
const unsigned char MAX_LEN = 35;

void generate_v3_address(unsigned int count);

#endif //MAIN_H

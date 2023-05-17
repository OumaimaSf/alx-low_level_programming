#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std -c *.c
ar rc liball.a *.o
ranlib liball.a

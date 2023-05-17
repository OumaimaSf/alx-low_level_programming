#!/bin/bash
gcc -Wall -Werror -Pedantic -Wextra -c *.c
ar rcs liball.a *.o


#!/bin/bash
gcc -Wall -pendic -Werror -Wextra -c *.c
ar rcs liball.a *.o


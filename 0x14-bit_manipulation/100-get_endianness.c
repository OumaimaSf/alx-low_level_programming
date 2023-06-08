#include <stdio.h>
#include "main.h"

/**
 * get_endianness - Checks the endianness.
 * 
 * Return: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	unsigned int n = 1;
	char *d = (char *)&n;

	if (*d == 1)
		return (1);
	else
		return (0);
}

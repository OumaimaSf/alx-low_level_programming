#include <stdio.h>
#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to print in binary.
 * @index: The index of the bit to retrieve.
 *
 * Return: The value of the bit at the given index, or -1 if an error.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int M;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	M = 1UL << index;
	return ((n & M) ? 1 : 0);
}

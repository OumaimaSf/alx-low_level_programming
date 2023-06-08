#include <stdio.h>
#include "main.h"

/**
 * flip_bits - Returns the number of bits to flip to get from one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: The number of bits to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int D = n ^ m;
	unsigned int C = 0;

	while (D > 0)
	{
		C += D & 1;
		D >>= 1;
	}

	return (C);
}

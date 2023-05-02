#include "main.h"

/*
 * swap_int - fontion swaps the values of two integers
 * 
 * @a: Pointer to the first integer to swap
 * @b: Pointer to the second integer to swap
 */

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

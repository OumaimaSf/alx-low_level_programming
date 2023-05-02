#include "main.h"

/*
 * void swap_int - swaps the values of two integers
 * @a: Pointer to the first integer to swap
 * @b: Pointer to the second integer to swap
 *
 * Return: None
 */

void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

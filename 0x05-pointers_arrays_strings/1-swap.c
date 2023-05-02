#include "main.h"

/*
 * void swap_int - swaps the values of two integers
 *
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

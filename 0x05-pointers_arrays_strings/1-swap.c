#include "main.h"

/*
 * swap_int - fontion swaps the values of two integers
 * 
 * @a: Pointer to the first integer to swap
 * @b: Pointer to the second integer to swap
 *
 * Description: This function swaps the values of two integers using pointers
 *
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

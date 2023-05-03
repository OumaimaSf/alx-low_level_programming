#include "main.h"

/**
 * print_array - prints n elements of an array of integers
 * @a: array to be printed
 * @n: number of elements to print
 *
 * Return: void
 */
void print_array(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (i != 0)
            _putchar(',');
        _putchar(' ');
        _putchar(a[i] / 10 + '0');
        _putchar(a[i] % 10 + '0');
    }
    _putchar('\n');
}

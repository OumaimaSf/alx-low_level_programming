#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: The string to print the second half of
 */
void puts_half(char *str)
{
	int i, len;

	len = 0;
	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		i = len / 2;
	else
		i = (len + 1) / 2;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

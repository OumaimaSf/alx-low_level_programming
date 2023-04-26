#include"main.h"
/**
 * add - adds two integers
 * @a: the first integer to be added
 * @b: the second integer to be added
 *
 * Return: the sum of the two integers
 */

int add(int a, int b)
{
	int sum = a + b;
	int digit, sign = 1;

	if (sum < 0)
	{
		sign = -1;
		sum *= -1;
		_putchar('-');
	}
	
	if (sum / 10)
		add(sum / 10, 0);

	digit = (sum % 10) + '0';
	_putchar(digit);

	return (a + b);
}

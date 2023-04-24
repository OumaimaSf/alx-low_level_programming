#include<stdio.h>
/**
 * main - Prints all possible combinations of two two-digit numbers
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int num1, num2, tens1, unit1, tens2, unit2;

	for (num1 = 0; num1 <= 99; num1++)
	{
		tens1 = num1 / 10;
		unit1 = num1 % 10;

		for (num2 = num1 + 1; num2 <= 99; num2++)
		{
			tens2 = num2 / 10;
			unit2 = num2 % 10;

			putchar(tens1 + '0');
			putchar(unit1 + '0');
			putchar(' ');
			putchar(tens2 + '0');
			putchar(unit2 + '0');

			if (!(num1 == 98 && num2 == 99))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}

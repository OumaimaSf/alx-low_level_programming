#include "main.h"
/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: size of buffer
 *
 * Return: pointer to result or 0 if result cannot be stored in buffer
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, i, j, k, sum, carry = 0;

	for (len1 = 0; n1[len1] != 0; len1++)
		;

	for (len2 = 0; n2[len2] != 0; len2++)
		;

	for (i = len1 - 1, j = len2 - 1, k = 0; k < size_r - 1; i--, j--, k++)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';
		if (i < 0 && j < 0 && sum == 0)
			break;
		carry = sum / 10;
		r[k] = sum % 10 + '0';
	}
	if (carry > 0)
	{
		if (k == size_r -1)
			return (0);
		r[k++] = carry + '0';
	}

	r[k] = '\0';
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		char temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}

	return (r);
}

#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */

int _atoi(char *s);
{
	int sign = 1;
	int num = 0;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		if (num != 0 && !(s[i] >= '0' && s[i] <= '9'))
			break;
		i++;
	}
	return (num * sign);
}

#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */

int _atoi(char *s)

{
	int i, n, sign;
	
	i = n = sign = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = (sign == 0) ? -1 : sign;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if (n > INT_MAX / 10 || (n == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
				return (sign == -1 ? INT_MIN : INT_MAX);
			n = n * 10 + (s[i] - '0');
		}
		else if (n != 0)
			break;
		i++;
	}
	return (sign == -1 ? -n : n);
}

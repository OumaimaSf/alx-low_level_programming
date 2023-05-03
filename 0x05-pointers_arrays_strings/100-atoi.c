#include <limits.h>
#include "main.h"
/**
 * _atoi - converts a string to an integer.
 * @s: string to convert.
 * Return: integer representation of string.
 */
int _atoi(char *s)
{
    int i, sign, n, len;

    i = 0;
    sign = 1;
    n = 0;
    len = 0;

    while (s[len] != '\0')
        len++;

    while (i < len && (s[i] < '0' || s[i] > '9'))
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }

    while (i < len && (s[i] >= '0' && s[i] <= '9'))
    {
        if (n > INT_MAX / 10 || (n == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
            return (sign == -1 ? INT_MIN : INT_MAX);
        n = n * 10 + (s[i] - '0');
        i++;
    }

    return (n * sign);
}

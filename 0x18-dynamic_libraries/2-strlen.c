#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: the sstring to be measured
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

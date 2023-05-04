#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0, i;

	/* Get length of destination string */
	while (dest[dest_len] != '\0')
		dest_len++;
	
	/* Copy source string to destination */
	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	/* Add null byte to end of destination */
	dest[dest_len + i] = '\0';

	return dest;
}

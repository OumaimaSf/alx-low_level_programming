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
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	i = 0;
	while(src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (dest);
}

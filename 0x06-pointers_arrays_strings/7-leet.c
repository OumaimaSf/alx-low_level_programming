#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: string to encode
 *
 * Return: a pointer to the encoded string
 */

char *leet(char *str)
{
	int i, j;
	char leet[] = "aAeEoOtTlL";
	char replace[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leet[j] != '\0'; j++)
		{
			if (str[i] == leet[j])
			{
				str[i] = replace[j];
				break;
			}
		}
	}

	return (str);
}

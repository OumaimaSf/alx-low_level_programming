#include "main.h"

/**
 * rot13 - Encodes a string using rot13
 * @str: string to be encoded
 *
 * Return: pointer to the encoded string
 */

char *rot13(char *str)
{
	int i, j;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; str[i] != '\0'; i++)
	{
		j = 0;
		while (alphabet[j] != '\0')
		{
			if (str[i] == alphabet[j])
			{
				str[i] = rot13[j];
				break;
			}
			j++;
		}
	}

	return (str);
}

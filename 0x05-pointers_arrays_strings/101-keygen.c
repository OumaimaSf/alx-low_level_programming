#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - Entry point for keygen program
 *
 * Return: Always 0
 */
int main (void)
{
	char password[84];
	int i, sum, n;

	srand(time(NULL));

	sum = 0;
	i = 0;

	while (sum < 2772 - 122)
	{
		n = rand() % 62;
		if (n < 10)
			password[i] = n + 48;
		else if (n < 36)
			password[i] = n + 55;
		else
			password[i] = n + 61;
		
		sum += password[i];
		i++;
	}

	password[i] = 2772 - sum - '\0';

	printf("%s", password);

	return (0);
}

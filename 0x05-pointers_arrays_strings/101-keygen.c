#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point for keygen program
 *
 * Return: Always 0
 */
int main (void)
{
	char password[100];
	int i, sum, diff;

	srand(time(0));

	for (i = 0, sum = 0; sum < 2772 - 122; i++)
	{
		password[i] = rand() % 94 + 33;
		sum += password[i];
	}

	diff = sum - 2772 + 122;
	password[i - 1] -= diff;

	password[i] = '\0';

	printf("%s", password);

	return (0);
}

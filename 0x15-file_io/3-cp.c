#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error_file - checks if files can be opened.
 * @fr: file from
 * @ft: file to
 * @argc: arguments vector.
 */
void error_file(int fr, int ft, char *argv[])
{
	if (fr == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (ft == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write from file %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - The entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fr, ft, err;
	char buffer[1024];
	ssize_t n_chars, n;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp fr ft");
		exit(97);
	}

	fr = open(argv[1], O_RDWR);
	ft = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(fr, ft, argv);

	n_chars = 1024;
	while (n_chars == 1024)
	{
		n_chars = read(fr, buffer, 1024);
		if (n_chars == -1)
			error_file(fr, -1, argv);
		n = write(ft, buffer, n_chars);
		if (n == -1)
			error_file(fr, ft, argv);
	}

	err = close(fr);
	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fr);
		exit(100);
	}
	err = close(ft);
	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ft);
		exit(100);
	}

	return (0);
}

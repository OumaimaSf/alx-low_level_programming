#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * cp - Copies the content of one file to another
 * @file_from: The source file.
 * @file_to: The destination file.
 *
 * Return: 0 on success, -1 on failure
 */

int cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, R;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't read from file %s\n", file_from);
		return (98);
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't write to %s\n", file_to);
		close(fd_from);
		return (99);
	}

	while ((R = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd_to, buffer, R) != R)
		{
			dprintf(STDERR_FILENO,"Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}

	if (R == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		return (98);
	}

	if (close(fd_from) == -1)
	{
		 dprintf(STDERR_FILENO,"Error: Can't close %d\n",fd_from);
		 return (100);
	}

	 if (close(fd_to) == -1)
        {
                 dprintf(STDERR_FILENO,"Error: Can't close %d\n",fd_to);
                 return (100);
        }

	return (0);
}

/**
 * main - Entry point of the cp program.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, 97 on incorrect number of arguments.
 */

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	return cp(argv[1], argv[2]);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes buffer
 * @file: Name of file buffer is stored in chars for.
 *
 * Return: Pointer newly-allocated in buffer
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - close file descriptors.
 * @fd: file descriptor to close
 */

void close_file(int fd)
{
	int x;

	x = close(fd);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies contents of a file to other file
 * @argv: An array of pointers to the arguments.
 * @argc: The number of the arguments supply to program.
 *
 * Return: 0 success
 *
 * Description: if the argu counts incorrect - exit code 97
 * if file_from does not exist or can't be read - exit code 98
 * If file_to can't be created or written to - exit code 99
 * if file_to or file_from can't close - exit code 100.
 */

int main(int argc, char *argv[])
{
	int from, to, q, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	q = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || q == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %sln", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, q);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			exit(99);
		}

		q = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (q > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads text file print STDOUT
 * @letters: num of letters to read
 * @filename: text file been read
 * Return: w - actual number of bytes read and is print
 *    0 if function fails or NULL when filename
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * read_textfile - Reads text file to print stdout
 * @filename: Pointer to the name of the file
 * @letters: number of letters to be read
 *
 * Return: the actual number of bytes to be read and printed
 * 0 if function fails or file name is null
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t l;
	ssize_t m;
	ssize_t n;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	l = open(filename, O_RDONLY);
	m = read(l, buf, letters);
	n = write(STDOUT_FILENO, buf, m);

	if (l == -1 || m == -1 || n == -1 || n != m)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(l);

	return (n);
}

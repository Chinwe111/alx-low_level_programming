#include <stdio.h>
#include "main.h"
/**
 * create_file - Creates a file
 * @filename: file to create
 * @text_content: pointer to string to write the file into
 *
 * Return: if success 1 otherwise -1 if it fails
 */

int create_file(const char *filename, char *text_content)
{
	int l, m, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	l = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	m = write(l, text_content, len);

	if (l == -1 || m == -1)
		return (-1);

	close(l);

	return (1);
}

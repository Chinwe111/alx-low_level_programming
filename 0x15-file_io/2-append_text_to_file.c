#include <stdio.h>
#include "main.h"
/**
 * _strlen - finds the length of a string
 * @str: pointer to the string
 *
 * Return: length of string
 */
size_t _strlen(char *str)
{
	size_t l;

	for (l = 0; str[l]; l++)
		;
	return (l);
}

/**
 * append_text_to_file - Appends a text at the end of a file
 * @filename: name of file
 * @text_content: string to add at the end of the file
 *
 * Return: 1 on success otherwise -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int mn;
	ssize_t len;

	if (filename == NULL)
		return (-1);
	mn = open(filename, O_WRONLY | O_APPEND);
	if (mn == -1)
		return (-1);
	if (text_content != NULL)
		len = write(mn, text_content, _strlen(text_content));
	close(mn);
	if (len == -1)
		return (-1);
	return (1);
}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * check97 - checks for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check98 - checks that file_from exists and can be read
 * @check: checks if true of false
 * @file: file_from name
 * @mn_from: file descriptor of file_from, or -1
 * @mn_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check98(ssize_t check, char *file, int mn_from, int mn_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (mn_from != -1)
			close(mn_from);
		if (mn_to != -1)
			close(mn_to);
		exit(98);
	}
}

/**
 * check99 - checks that file_to was created and/or can be written to
 * @check: checks if true of false
 * @file: file_to name
 * @mn_from: file descriptor of file_from, or -1
 * @mn_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check99(ssize_t check, char *file, int mn_from, int mn_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (mn_from != -1)
			close(mn_from);
		if (mn_to != -1)
			close(mn_to);
		exit(99);
	}
}

/**
 * check100 - checks that file descriptors were closed properly
 * @check: checks if true or false
 * @mn: file descriptor
 *
 * Return: void
 */
void check100(int check, int mn)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", mn);
		exit(100);
	}
}
/**
 * main - opies the content of a file to another file.
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int mn_from, mn_to, close_to, close_from;
	ssize_t lenr, lenw;
	char buf[1024];
	mode_t file_perm;

	check97(argc);
	mn_from = open(argv[1], O_RDONLY);
	check98((ssize_t)mn_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	mn_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check99((ssize_t)mn_to, argv[2], mn_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(mn_from, buf, 1024);
		check98(lenr, argv[1], mn_from, mn_to);
		lenw = write(mn_to, buf, lenr);
		if (lenw != lenr)
			lenw = -1;
		check99(lenw, argv[2], mn_from, mn_to);
	}
	close_to = close(mn_to);
	close_from = close(mn_from);
	check100(close_to, mn_to);
	check100(close_from, mn_from);
	return (0);
}

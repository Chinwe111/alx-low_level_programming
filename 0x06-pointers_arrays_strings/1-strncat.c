#include <stdio.h>
#include "main.h"
/**
 * _strncat - concatenate two strings
 * @src: source of sting
 * @dest: destination of string
 * @n: length of string
 * Return: string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
	{
		continue;
	}
	for (j = 0 src[j] != '\0' && j < n; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] '\0';
	return (dest);
}

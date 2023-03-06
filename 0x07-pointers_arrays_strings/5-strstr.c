#include <stdio.h>
#include "main.h"
/**
 * _strstr - locates a substring
 * @haystack: the longer the string to search
 * @needle: the first occurrence of the substring
 * Return: A pointer of the substring or @NULL if not found
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;

	while (haystack[i])
	{
		while (needle[j] && (haystack[i] == needle[0]))
		{
			if (haystack[i + j] == needle[j])
				j++
			else
				break;
		}
		if (needle[j])
		{
			i++;
			j = 0;
		}
		else
			return (haystack + i);
	}
	return (0);
}

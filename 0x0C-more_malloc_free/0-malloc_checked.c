#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - function should cause normal process termination
 * @b: allocated memory
 * Return: pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *i;

	i = malloc(b);
	if (i == NULL)
		exit(98);
	return (i);
}

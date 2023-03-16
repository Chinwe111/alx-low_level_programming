#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * *array_range - creates an array of intergers
 * @min: minimum range of value stored
 * @max: maximun range of value stored
 * Return: pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int *ptr;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	ptr = malloc(sizeof(int) * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		ptr[i] = min++;

	return (ptr);
}

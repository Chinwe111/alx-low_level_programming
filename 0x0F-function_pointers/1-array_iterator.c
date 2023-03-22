#include <stdio.h>
#include "function_pointers.h"
/**
 * array_iterator - funtion given as a parameter on
 * each element of an array
 * @array: array
 * @size: size of array
 * @action: pointer to print in regular or hex
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array && action)
	{
		i = 0;
		while (i < size)
		{
			action(array[i]);
			i++;
		}
	}
}

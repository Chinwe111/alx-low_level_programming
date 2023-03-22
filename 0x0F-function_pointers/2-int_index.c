#include <stdio.h>
#include "function_pointers.h"
/**
 * int_index - returns the index of thee first element
 * @array: array
 * @size: the number of elements
 * @cmp: pointer to the function to be used
 * Return: 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int a = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (a < size)
			{
				if (cmp(array[a]))
					return (a);

				a++;
			}
		}
	}

	return (-1);
}

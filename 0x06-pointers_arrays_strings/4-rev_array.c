#include <stdio.h>
#include "main.h"
/**
 * reverse_array - reverse array of integers
 * @a: array
 * @n: integer
 */

void reverse_array(int *a, int n)
{
	int i;
	int j;

	for (1 = 0; (i < (n - 1) / 2); i++)
	{
		j = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = j;
	}
}

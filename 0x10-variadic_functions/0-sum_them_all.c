#include "variadic_functions.h"
#include <stdio.h>
/**
 * sum_them_all - adds all the numbers
 * @n: the numbers of parameters passed
 * Return: 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int x;
	va_list nl;

	va_start(nl, n);

	if (n == 0)
		return (0);

	for (x = 0; x < n; x++)
		sum += va_arg(nl, int);

	va_end(nl);

	return (sum);
}

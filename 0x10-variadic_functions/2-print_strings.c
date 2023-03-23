#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_strings - prints string
 * @separator: separator between two strings
 * @n: number of parameters
 * Return: 0
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	char *str;
	unsigned int x;
	va_list nl;

	va_start(nl, n);
	if (separator == NULL)
		separator = "";

	for (x = 0; x < n; x++)
	{
		str = va_arg(nl, char*);
		if (str == NULL)
			str = "(nil)";
		printf("%s", str);
		if (x < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(nl);
}


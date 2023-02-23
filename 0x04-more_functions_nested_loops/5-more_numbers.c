#include <stdio.h>
#include "main.h"
/**
 * more_numbers - prints 10 times the numbers
 */

void more_numbers(void)
{
	int i;
	int j;

	for (i = 1; i <= 10; i++)
	{
		if (j >= 10)
			_putchar('1');
			_putchar(j % 10 + '0');
	}
	_putchar('\n');
}


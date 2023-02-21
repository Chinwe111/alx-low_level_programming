#include <stdio.h>
#include "main.h"
/**
 * print_alphabet_x10 - print alphabet 10 times
 */

void print_alphabet_x10(void)
{
	char alph;
	int i;

	for (i = 1; i <= 10; i++)
	{
		for (alph = 'a'; alph <= 'z'; alph++)
			_putchar(alph);

		_putchar('\n');
	}
}

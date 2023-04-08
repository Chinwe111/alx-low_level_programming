#include <stdio.h>
#include "main.h"
/**
 * flip_bits - flip the number of bits to get from
 * one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int div, current;
	unsigned int x, y;

	x = 0;
	current = 1;
	div = n ^ m;

	for (y = 0; y < (sizeof(unsigned long int) * 8); y++)
	{
		if (current == (div & current))
			x++;
		current <<= 1;
	}

	return (x);
}

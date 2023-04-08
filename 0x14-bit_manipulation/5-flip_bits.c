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
	int x, y;

	y = 0;
	current = 1;
	div = n ^ m;

	for (x = 0; x < (sizeof(unsigned long int) * 8); x++)
	{
		if (current == (div & current))
			y++;
		current <<= 1;
	}

	return (y);
}

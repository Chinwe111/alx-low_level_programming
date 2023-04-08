#include <stdio.h>
#include "main.h"
/**
 * clear_bit - sets the value of bit to 0 at a given index
 * @n: pointer number to change
 * @index: index of the bit to set
 *
 * Return: 1 if success otherwise -1 if error occurs
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	x = ~(1 << index);
	*n = *n & x;

	return (1);
}

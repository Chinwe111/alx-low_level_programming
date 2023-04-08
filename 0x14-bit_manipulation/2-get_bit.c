#include <stdio.h>
#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index
 * @n: bits to be checked
 * @index: checks bit to get
 *
 * Return: The value of bit at index otherwise -1 if error
 * occurs
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int div_val, current;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	div_val = 1 << index;
	current = n & div_val;
	if (current == div_val)
		return (1);

	return (0);
}

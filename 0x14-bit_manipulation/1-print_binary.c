#include <stdio.h>
#include "main.h"
/**
 * _power - To calculate the base and power
 * @base: base to be calculated
 * @pow: power to be calculated
 *
 * Return: value of calculated base and power
 */

unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned long int num;
	unsigned int x;

	num = 1;
	for (x = 1; x <= pow; x++)
		num *= base;
	return (num);
}

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print in binary
 *
 * Return: 0
 */

void print_binary(unsigned long int n)
{
	unsigned long int dev, current;
	int x;

	x = 0;
	dev = _power(2, sizeof(unsigned long int) * 8 - 1);

	while (dev != 0)
	{
		current = n & dev;
		if (current == dev)
		{
			x = 1;
			_putchar('1');

		}
		else if (x == 1 || dev == 1)
		{
			_putchar('0');
		}
		dev >>= 1;
	}
}

#include <stdio.h>
#include "main.h"
/**
 * get_endianness - checks for endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	int x;
	char *c;

	x = 1;
	c = (char *)&x;

	return (*c);
}

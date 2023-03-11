#include <stdio.h>
#include "main.h"
/**
 * _abs - computes the absolute value of an integer
 * @n: the int in question
 *
 * Return: the absolute of the integer
 */

int _abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

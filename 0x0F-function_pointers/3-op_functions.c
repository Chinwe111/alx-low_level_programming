#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * op_add - returns the sum of two numbers
 * @a: first number
 * @b: second number
 * Return: Sum of a and b
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - returns the difference of two numbers
 * @a: first number
 * @b: second number
 * Return: Difference of a and b
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - returns the multiplication of two numbers
 * @a: first number
 * @b: second number
 * Return: Multiplication of a and b
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - returns the division of two numbers
 * @a: first number
 * @b: second number
 * Return: Quotient of a and b
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - returns the remainder of division of
 * two numbers
 * @a: first number
 * @b: second number
 * Return: The remainder of division of a and b
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}

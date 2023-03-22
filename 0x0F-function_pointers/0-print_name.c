#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - a function that prints s name
 * @name: string to add
 * @f: pointer to funtion
 *
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}

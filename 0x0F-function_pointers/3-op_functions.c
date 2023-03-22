#include "3-calc.h"
#include <stdlib.h>
#include <string.h>
/**
 * get_op_func - select the correct funct to perform
 * the opertion
 * @s: the operator passed as argument
 *
 * Return: A pointer to the funtion
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{ "+", op_add },
	{ "-", op_sub },
	{ "*", op_mul },
	{ "/", op_div },
	{ "%", op_mod },
	{ NULL, NULL }
	};
	int a = 0;

	while (a < 5)
	{
		if (strcmp(s, ops[a].op) == 0)
			return (ops[a].f);

		a++;
	}

	return (0);
}

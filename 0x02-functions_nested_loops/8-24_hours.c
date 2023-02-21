#include <stdio.h>
#include "main.h"
/**
 * jack_bauer - Prints every minute of the day of Jack Bauer,
 *		starting from 00:00 to 23:59
 *
 */

void jack_bauer(void)
{
	int hur, min;

	for (hur = 0; hur <= 23; hur++)
	{
		for (min = 0; min <= 59; min++)
		_putchar((hur / 10) + '0');
		_putchar((hur % 10) + '0');
		_putchar(':');
		_putchar((min / 10) + '0');
		_putchar((min % 10) + '0');
		_putchar('\n');
	}
}

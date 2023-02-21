#include <stdio.h>
#include "main.h"
/**
 * jack_bauer - prints every minutes of the day of Jack Bauer
 * @min: is the int in question
 * @hr: is the int in question
 * Return: Value of every minute of the day
 */

void jack_bauer(void min, hr)
{
	int min = 0;
	int hr = 0;

	for (hr = 0; hr < 24; hr++)
	{
	for (min = 0; min < 59; min++)
	{
	printf("%02d:%02d", hr, min);
		printf('\n');
	}
	printf("%02d:%02d", hr, min);
		printf('\n');
	}
}

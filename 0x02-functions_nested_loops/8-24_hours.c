#include <stdio.h>
#include "main.h"
/**
 * jack_bauer - prints every minutes of the day of Jack Bauer
 *
 */

void jack_bauer(void)
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

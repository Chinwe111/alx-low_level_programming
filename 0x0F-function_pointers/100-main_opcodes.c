#include <stdio.h>
#include <stdlib.h>
/**
 * print_opcodes - prints the opcodes of this program
 * @a: address of the main function
 * @n: number of bytes to print
 * Return: void
 */

void print_opcodes(char *a, int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		printf("%.2hhx", a[x]);
		if (x < n - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * main - prints the opcodes of its own
 * main function
 * @argc: number of arguments
 * @argv: array of pointers to the argument
 * Return: 0
 */

int main(int argc, char **argv)
{
	int y;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	y = atoi(argv[1]);
	if (y < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes((char *)&main, y);
	return (0);
}

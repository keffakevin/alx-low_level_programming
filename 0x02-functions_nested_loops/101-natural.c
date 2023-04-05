#include "main.h"
#include <stdio.h>
/**
 * main - check the code
 * Return: Always 0.
 */
int main(void)
{
	int sum3 = 0, sum7 = 0;
	int i;

	for (i = 0; i < 1024; i++)
	{
		if (i % 3 == 0)
		{
			sum3 += i;
		}
		if (i % 5 == 0)
		{
			sum7 += i;
		}
	}
	printf("%d\n", sum3 + sum7);
	return 0;
}

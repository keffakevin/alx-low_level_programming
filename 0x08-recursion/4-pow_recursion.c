#include "main.h"
#include <stdio.h>
/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: string to print
 * Return:0
 */
int _pow_recursion(int b, int a)
{
	if (a<0)
	{
	return -1;
	}
		else if (a != 0)
		return (b * _pow_recursion(b, a - 1));
		else
		return 1;
}

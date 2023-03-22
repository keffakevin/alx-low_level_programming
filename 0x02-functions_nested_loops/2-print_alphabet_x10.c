#include "main.h"
/**
 * print_alphabet_x10 - print ten times the alphabetic
 * Return:0 (Success)
 */
void print_alphabet_x10(void)
{
int n;
int k;
for (n = 1; n <= 10; n++)
{
for (k = 'a'; k <= 'z'; k++)
	_putchar (k);
_putchar ('\n');
}
}

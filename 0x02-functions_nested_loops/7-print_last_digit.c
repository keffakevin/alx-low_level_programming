#include"main.h"
/**
 * print_last_digit - function that print alahabetic
 * @a:parameter description
 * Return:1 and return 0 otherwise
 */
int print_last_digit(int a)
{
int k;
k = a % 10;
if (a < 0)
k = -k;
_putchar (k + '0');
return (k);
}

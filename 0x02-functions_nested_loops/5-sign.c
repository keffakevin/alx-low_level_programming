#include "main.h"
 /**
 * print_sign - function that print alahabetic
 * @c:parameter description
 * Return:1 and return 0 otherwise
 */
int print_sign(int n);
{
if (n > 0)
{
_putchar('+');
return (1);
}
else if (n == 0)
{
_putchar('0');
return (0);
}
else
{
_putchar('-');
return (-1);
}
}

#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */
/**
 * main - main function that print reverse single numbers
 * Return: 0 (Success)
 */
int main(void)
{
int n;
int a;
/* your code goes there */
for (n = 0; n < 10 ; n++)
{
	for (a = 1; a < 10; a++)
	{
	if (n < a && n != a)
	{
	putchar(n + '0');
	putchar(a + '0');
putchar(';');
putchar(' ');
	}
	}
putchar (n + '0');
}
putchar ('\n');
return (0);
}

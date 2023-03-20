#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */
/**
 * main - main function that print sequence of three digit
 * Return:0 (Success)
 */
int main(void)
{
int n;
int a;
int j;
/* your code goes there */
for (n = 0; n < 10 ; n++)
{
for (a = 1; a < 10 ; a++)
{
for (j = 2; j < 10 ; j++)
	if (n < a && a < j)
	{
	putchar (n + '0');
	putchar (a + '0');
	putchar (j + '0');
	if (n + a + j != 24)
	{
	putchar (',');
	putchar (' ');
	}
	}
{
}
}
}
putchar('\n');
return (0);
}

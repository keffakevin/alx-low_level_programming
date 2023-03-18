#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */
/**
 * main -main function that print numbers using putchar
 * Return:0 (Success)
 */
int main(void)
{
int n;
/* your code goes there */
for (n = 0; n < 10; n++)
	putchar(n + '0');
putchar('\n');
return (0);
}

#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */
/**
 * main -main that print alphabetic reverse
 * Return:0 (Success)
 */
int main(void)
{
int n;
/* your code goes there */
for (n = 'z' ; n >= 'a' ; n--)
	putchar(n);
putchar('\n');
return (0);
}

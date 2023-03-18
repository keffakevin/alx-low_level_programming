#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include<stdio.h>
/* betty style doc for function main goes there */
/**
 * main -main function to print alphabet
 * Return:0 (Success)
 */
int main(void)
{
char i;
/* your code goes there */
for (i = 'a'; i <= 'z' ; i++)
	putchar(i);
for (i = 'A'; i <= 'Z' ; i++)
	putchar(i);
putchar('\n');
return (0);
}

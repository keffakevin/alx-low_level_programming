#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */
/**
 * main - main function to print alphabet without letter q and e
 * Return: (0)
 */
int main(void)
{
char i;
/* your code goes there */
for (i = 'a' ; i <= 'z' ; i++)
	if (i != 'q' && i != 'e')
		putchar(i);
putchar ('\n');
return (0);
}

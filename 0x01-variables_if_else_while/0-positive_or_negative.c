#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */
/**
 * main - This is the main loop function
 * Return:0 (Success)
 */
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
		printf("%d is Positive:\n", n);
	else if (n == 0)
		printf("%d is Zero:\n", n);
	else
		printf("%d is Negative:\n", n);
	return (0);
}

#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/**
* main - This is a prograam print a line with puts function
* Return:0 (Success)
*/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n>0)
		printf("%d Number is Positive:\n", n);
	else if (n<0)
		printf("%d Number is Negative:\n", n);
	else
		printf("%d Number is Zero: \n", n);
	return (0);
}

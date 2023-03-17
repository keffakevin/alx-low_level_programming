#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */
/**
 * main -main  function display last digit
 * Return: 0 (Success)
 */
int main(void)
{
int n;
int k;
srand(time(0));
n = rand () - RAND_MAX / 2;
/* your code goes there */
k = n % 10;
if (m > 5)
	printf("Last digit of is %d and %d is greater than 5\n", n, m);
else if (m == 0)
	printf("Last digit of %d is %d is zero\n", n, m);
else if (m < 6 && m != 0)
	printf("Last digit of is %d and %d is less than 6 and not 0\n", n, m");
return (0);
}

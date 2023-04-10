#include <stdio.h>
#include <stdlib.h>
/**
 * main- function that print alahabetic
 * @argc:parameter description
 * @argv:parameter description
 * Return:0
 */
int main(int argc, char *argv[])
{
int a, b, sum;
if (argc != 3)
{
printf("Error\n");
return (-1);
}
a = atoi(argv[1]);
b = atoi(argv[2]);
sum = a *b;
printf("%d\n", sum);
return (0);
}

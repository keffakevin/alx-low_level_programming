#include <stdio.h>
/**
* main - This is a prograam print a line with puts function
*Return: 0 (Success)
*/
int main(void)
{
char a;
int b;
long int c;
long long int d;
float e;
printf("Size of float: %zu byte(s)\n",(unsigned long) sizeof(a)); 
printf("Size of int: %zu byte(s)\n", (unsigned long) sizeof(b));
printf("Size of int: %zu byte(s)\n", (unsigned long) sizeof(c));
printf("Size of float: %zu byte(s)\n", (unsigned long) sizeof(d));
printf("Size of float: %zu byte(s)\n", (unsigned long) sizeof(d));
return (0);
}

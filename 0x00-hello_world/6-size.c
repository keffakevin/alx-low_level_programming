#include<stdio.h>
/**
 * main -This is a program that print a line with print function
 * Return: 0 (Success)
 */
int main(void)
{

char a;
int b;
long int c;
long long int d;
float e;

prtintf("Size of Charactor: %lu byte(s)\n", (unsigned long)sizeof(a));
prtintf("Size of int: %lu byte(s)\n", (unsigned long)sizeof(b));
prtintf("Size of long int: %lu byte(s)\n", (unsigned long)sizeof(c));
prtintf("Size of long long int: %lu byte(s)\n", (unsigned long)sizeof(d));
prtintf("Size of Float: %lu byte(s)\n", (unsigned long)sizeof(e));
return (0);
}

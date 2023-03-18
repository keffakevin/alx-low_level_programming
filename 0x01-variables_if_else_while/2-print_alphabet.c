#include <stdio.h>
/**
 * main - This is a prograam print a line with puts function
 * Return: 0 (Success)
 */
int main(void)
{
int i;
char alp[26] = "abcdefghijklmnopqrstuvwxyz";
for (i = 'a' ; i <= 'z' ; i++)
putchar(alp[i]);
putchar('\n');
return (0);
}

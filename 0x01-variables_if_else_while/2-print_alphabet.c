#include <stdio.h>
/**
 * main - This is a prograam print a line with puts function
 * Return: 0 (Success)
 */
int main(void)
{
	char alp[26] = "abcdefghijklmnopqrstuvwxyz";
	int i;
	for (i = 0; i < 26; i++)
		putchar(alp[i]);
	putchar('\n');
	return (0);
}

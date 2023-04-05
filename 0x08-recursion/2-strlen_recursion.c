#include "main.h"
#include <stdio.h>
/**
* _puts_recursion - prints a string, followed by a new line
* @s: string to print
* Return:0
*/

int _strlen_recursion(char *s)
{
int x = 0;
if (*s != '\0')
{
x=x+1;
return _strlen_recursion(s + 1);
} else
{
return x;
}
}

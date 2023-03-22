#include "main.h"
/**
* _islower  program to print lower case and retun one or otherwise
* Return:0 (Success)
*/
int _islower(int c)
{
	if (c>= 97 && c <= 122)
		return (1);
	else 
		return (0);
}

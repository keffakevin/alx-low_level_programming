#include "main.h"
/**
*_islower -function that print lower case
*c paratmeter to be printed
* Return:1 is there is a upper case and 0 otherwise
*/
int _islower(int c)
{
if (c >= 97 && c <= 122)
return (1);
else
return (0);
}

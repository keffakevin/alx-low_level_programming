#include "main.h"
/**
 * _isalpha - function that print alahabetic
 * @c:parameter description
 * Return:1 and return 0 otherwise
 */
int _isalpha(int c)
{
if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	return (1);
else
	return (0);

}

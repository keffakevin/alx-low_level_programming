#include <stdio.h>
#include "main.h"
/**
 * binary_to_uint - converts binary to unsigned integer
 *
 * @b: pointer to string of 0 and 1 chars
 *
 * Return: converted number, or 0 if there is an error
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		result <<= 1;
		if (*b == '1')
			result += 1;
		b++;
	}

	return (result);
}

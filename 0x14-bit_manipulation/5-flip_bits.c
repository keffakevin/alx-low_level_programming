#include <stdio.h>
#include "main.h"
/**
 * flip_bits - returns the number of bits to flip to get from one
 *
 * @n: unsigned long integer
 * @m: unsigned long integer
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int xor_value = n ^ m;

	while (xor_value != 0)
	{
		if (xor_value & 1)
			count++;
		xor_value >>= 1;
	}

	return (count);
}

#include <stdio.h>
#include <stdlib.h>

/*
 * add - Adds two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The sum of the two integers.
 */
int add(int a, int b)
{
	return a + b;
}

/*
 * sub - Subtracts two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The result of subtracting the second integer from the first.
 */
int sub(int a, int b)
{
	return a - b;
}

/*
 * mul - Multiplies two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The product of the two integers.
 */
int mul(int a, int b)
{
	return a * b;
}

/*
 * safe_div - Safely divides two integers.
 * @a: The dividend.
 * @b: The divisor.
 *
 * Return: The result of dividing the first integer by the second.
 * If the divisor is zero, returns 0.
 */
int safe_div(int a, int b)
{
	if (b == 0)
	{
	return 0; /* Handle division by zero */
	}
	return a / b;
}

/*
 * mod - Computes the modulo of two integers.
 * @a: The dividend.
 * @b: The divisor.
 *
 * Return: The remainder of dividing the first integer by the second.
 * If the divisor is zero, returns 0.
 */
int mod(int a, int b)
{
	if (b == 0)
	{
	return 0; /* Handle modulo by zero */
	}
	return a % b;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
/**
 * multiply - multiply two positive numbers
 * @num1: the first number
 * @num2: the second number
 * Return: a pointer to the result
 */
char *multiply(const char *num1, const char *num2)
{
	int len1 = 0, len2 = 0, i, j, k, carry = 0;
	char *result;

	while (num1[len1] != '\0')
		len1++;
	while (num2[len2] != '\0')
		len2++;
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';
	result[i] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			k = i + j + 1;
			carry += (num1[i] - '0') * (num2[j] - '0') + (result[k] - '0');
			result[k] = carry % 10 + '0';
			carry /= 10;
		}
		result[i] += carry;
	}
	while (*result == '0' && *(result + 1) != '\0')
		result++;
	return (result);
}

/**
 * is_digit_string - checks if a string only contains digits
 * @str: the string to check
 * Return: 1 if the string only contains digits, otherwise 0
 */
int is_digit_string(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
/**
 * main - entry point
 * @argc: the argument count
 * @argv: the argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;
	(void) argc;
/**
	* if (argc != 3)
	*{
	*	printf("Error\n");
	*	return (98);
	*}
	*/
	if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
	{
		printf("Error\n");
		return (98);
	}
	num1 = argv[1];
	num2 = argv[2];
	result = multiply(num1, num2);
	printf("%s\n", result);
	free(result);
	return (0);
}

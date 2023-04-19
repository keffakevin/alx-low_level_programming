#include "3-calc.h"

/**
 * get_op_func - selects the correct function to perform the
 *       operation asked by the user.
 * @s: operator passed as argument.
 *
 * Return: pointer to the function that corresponds to the operator
 *         given as a parameter.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{"+", add},
	{"-", sub},
	{"*", mul},
	{"/", div},
	{"%", mod},
	{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op != NULL)
{
	if (*(ops[i].op) == *s)
	return (ops[i].f);
	i++;
}
return (NULL);
}

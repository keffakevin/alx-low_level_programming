#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * array_range - creates an array of integers from min to max (inclusive)
 * @min: the minimum value of the range
 * @max: the maximum value of the range
 *
 * Return: On success, a pointer to the newly created array. On failure, NULL.
 */
int *array_range(int min, int max)
{
int *arr, i, size;

	if (min > max)
	return (NULL);

size = max - min + 1;
arr = malloc(sizeof(int) * size);
	if (!arr)
	return (NULL);

	for (i = 0; i < size; i++)
	arr[i] = min + i;

	return (arr);
}

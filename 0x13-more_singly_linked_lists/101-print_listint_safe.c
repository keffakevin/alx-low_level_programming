#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the first node of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current;

	if (!head)
	exit(98);

	current = head;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

	if (current > current->next)
	{
		printf("-> [%p] %d\n", (void *)current->next, current->next->n);
		break;
	}

	current = current->next;
	}

	return (count);
}

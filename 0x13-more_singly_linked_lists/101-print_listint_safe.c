#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: a pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	size_t count = 0;

	if (head == NULL)
	{
	printf("[0] (nil)\n");
	exit(98);
	}

	current = head;
	while (current != NULL)
	{
	printf("[%p] %d\n", (void *)current, current->n);
	count++;
	if (current <= current->next)
	{
	printf("-> [%p] %d\n", (void *)current->next, current->next->n);
	exit(98);
	}
	current = current->next;
	}

	return (count);
}

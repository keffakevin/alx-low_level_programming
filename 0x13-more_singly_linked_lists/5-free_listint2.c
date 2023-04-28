#include <stdlib.h>
#include "lists.h"
#include <string.h>
#include <stdio.h>
/**
 * free_listint2 - Frees a listint_t list
 * @head: A pointer to a pointer to the head of the list
 *
 * Description: This function frees a `listint_t` list.
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
	return;

	while (*head != NULL)
	{
	current = *head;
	*head = (*head)->next;
	free(current);
	}

	*head = NULL;
}

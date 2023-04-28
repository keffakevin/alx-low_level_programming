#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list
 * @head: A pointer to the head of the list
 * @index: The index of the node, starting at 0
 *
 * Description: This function returns the nth node of a `listint_t.
 *
 * Return: A pointer to the nth node, or NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current;

	current = head;
	for (i = 0; current != NULL && i < index; i++)
	current = current->next;

	if (i != index)
	return (NULL);

	return (current);
}

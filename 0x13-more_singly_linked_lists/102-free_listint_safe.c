#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: pointer to a pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *temp;
	size_t count = 0;

	while (current != NULL && current > current->next)
	{
	temp = current;
	current = current->next;
	count++;
	free(temp);
	}

	count++;
	free(current);
	*h = NULL;

	return (count);
}

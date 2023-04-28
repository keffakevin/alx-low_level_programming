#include <stdlib.h>
#include "lists.h"
/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * @head: A pointer to a pointer to the head of the list
 *
 * Description: This function deletes the head node of a `listint_t.
 *
 * Return: The head node's data (n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
	return (0);

	temp = *head;
	n = (*head)->n;
	*head = (*head)->next;
	free(temp);

	return (n);
}

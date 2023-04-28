#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: A pointer to the head of the list
 *
 * Description: This function finds the loop in a linked list and returns the
 * address of the node where the loop starts, or NULL if there is no loop. The
 * function only uses a maximum of two variables and does not use malloc, free,
 * or arrays.
 *
 * Return: The address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
	return (NULL);

	/* Use Floyd's cycle-finding algorithm */
	slow = head;
	fast = head;
	while (fast != NULL && fast->next != NULL)
	{
	slow = slow->next;
	fast = fast->next->next;
	if (slow == fast)
	{
	/* Loop found */
	slow = head;
		while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return (slow);
	}
	}

	/* Loop not found */
return (NULL);
}

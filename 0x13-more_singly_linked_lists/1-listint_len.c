#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t len = 0;  /* Initialize the length to zero. */

    /* Traverse the list and count the nodes. */
	while (h != NULL)
	{
	len++;       /* Increment the length counter. */
	h = h->next; /* Move to the next node. */
	}

	return (len);      /* Return the final length. */
}

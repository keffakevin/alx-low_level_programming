#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * free_list - Frees a linked list_t list and adds a new node at the beginning
 * @head: Pointer to the first node of the list
 */

void free_list(list_t *head)
{
	list_t *temp;

	/* Traverse the list and free each node */
	while (head != NULL)
	{
	temp = head;
	head = head->next;
	free(temp);
	}

    /* Add a new node at the beginning of the list */
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	{
/* Handle memory allocation error */
	fprintf(stderr, "Error: Unable to allocate memory\n");
	exit(EXIT_FAILURE);
	}

	new_node->data = 0;
	new_node->next = head;
	head = new_node;
}

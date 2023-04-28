#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * add_node_end - Adds a new node at the end of a list_t list
 *
 * @head: A pointer to a pointer to the head of the list
 * @str: The string to be added to the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *last_node;
	char *str_copy;

	if (!head || !str)  /* Check for invalid arguments */
	return (NULL);

	new_node = malloc(sizeof(list_t));  /* Allocate memory for the new node */
	if (!new_node)  /* Check for allocation failure */
	return (NULL);

	str_copy = strdup(str);  /* Duplicate the string */
	if (!str_copy)
	{  /* Check for allocation failure */
	free(new_node);
	return (NULL);
	}

	new_node->str = str_copy;
	new_node->next = NULL;

	if (*head == NULL)
	{  /* If the list is empty, the new node is the head */
	*head = new_node;
	}
	else
	{
	last_node = *head;
	while (last_node->next != NULL)  /* Traverse the list to find the last node */
	last_node = last_node->next;
	last_node->next = new_node;
	}

	return (new_node);
}

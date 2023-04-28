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

	if (!head || !str)
	{
	}
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
	return (NULL);
	}

	str_copy = strdup(str);
	if (!str_copy)
	{
	free(new_node);
	return (NULL);
	}

	new_node->str = str_copy;
	new_node->next = NULL;

	if (*head == NULL)
	{
	*head = new_node;
	}
	else
	{
	last_node = *head;
	while (last_node->next != NULL)
	{
	last_node = last_node->next;
	}
	last_node->next = new_node;
	}

	return (new_node);
}

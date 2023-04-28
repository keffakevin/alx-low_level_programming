#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * free_list - frees a linked list
 * @head: pointer to the head of the list
 *
 * This function frees all the memory allocated for a linked list.
 * It iterates through the list and frees each node, until the end
 * of the list is reached (when the next pointer of a node is NULL).
 *
 * Return: void
 */
void free_list(list_t *head)
{
    list_t *current = head;
    list_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

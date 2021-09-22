#include "monty.h"
/**
 * free_stack - Function that frees a stack
 * Return: Void.
 * @head: Head of the double linked list
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
	{
		return;
	}
	free_stack(head->next);
	free(head);
}

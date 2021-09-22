#include "monty.h"
/**
 * _add - Function that adds the top two elements of the stack.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _add(stack_t **head, unsigned int line_number)
{
	int sum = 0;
	stack_t *delete_node;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(STDERR_FILENO, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;

	delete_node = *head;
	*head = delete_node->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(delete_node);
}
/**
 * _nop - Function that doesn’t do anything.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

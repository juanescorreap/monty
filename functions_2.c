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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
/**
 * _sub - Function that doesn’t do anything.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *delete_node;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;

	delete_node = *head;
	*head = delete_node->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(delete_node);
}
/**
 * _div - Function that doesn’t do anything.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _div(stack_t **head, unsigned int line_number)
{
	int div;
	stack_t *delete_node;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = (*head)->n / (*head)->next->n;
	(*head)->next->n = div;

	delete_node = *head;
	*head = delete_node->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(delete_node);
}
/**
 * _mul - Function that doesn’t do anything.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _mul(stack_t **head, unsigned int line_number)
{
	int mul;
	stack_t *delete_node;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*head)->n * (*head)->next->n;
	(*head)->next->n = mul;

	delete_node = *head;
	*head = delete_node->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(delete_node);
}

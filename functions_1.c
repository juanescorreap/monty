#include "monty.h"
/**
 * _push - Function that pushes an element to the top of stack.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int number = 0;
	char *string;

	if (head == NULL)
	{
		return;
	}
	string = strtok(NULL, DELIMITERS);
	if (!number_verifier(string))
	{
		fprintf(stderr, "L%u: usage: push integer", line_number);
		freedata(data);
		return(EXIT_FAILURE);
	}
	number = atoi(string);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		freedata(data);
		return(EXIT_FAILURE);
	}
	new_node->n = number;
	new_node->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;
}
/**
 * _pall - Function that prints all the values on the stack,
 * starting from the top of the stack.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}
/**
 * _pint - Function that prints the value at the top of the stack,
 * followed by a new line
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		return(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * _pop - Function that removes the top element of the stack.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *delete_node;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return(EXIT_FAILURE);
	}
	delete_node = *head;
	*head = delete_node->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(delete_node);
}
/**
 * _swap - Function that swaps the top two elements of the stack.
 * Return: Void.
 * @head: Head of a double linked list
 * @line_number: Number of lines executed before an error is printed
 */
void _swap(stack_t **head, unsigned int line_number)
{
	int i = (*head)->n;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return(EXIT_FAILURE);
	}
	(*head)->n = (*head)->next->n;
	(*head)->next->n = i;
}

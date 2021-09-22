#include "monty.h"

/**
 * get_op_cases - Function converts numbers to char.
 * Return: Void.
 * @format: Sting being searched for %
 * @i: holds the place in which % was found in the string
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
		printf("L%u: usage: push integer", line_number);
		freedata(data);
		exit(EXIT_FAILURE);
	}
	number = atoi(string);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed");
		freedata(data);
		exit(EXIT_FAILURE);
	}
	new_node->n = number;
	new_node->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;
}
/* pall function */
void _pall(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	while (*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}
/* pint function */
void _pint(stack_t **head, unsigned int line_number)
{
	(void) head;
    (void) line_number;
}
/* pop function */
void _pop(stack_t **head, unsigned int line_number)
{
	(void) head;
    (void) line_number;
}
/* swap function */
void _swap(stack_t **head, unsigned int line_number)
{
	(void) head;
    (void) line_number;
}
/* add function */
void _add(stack_t **head, unsigned int line_number)
{
	(void) head;
    (void) line_number;
}
/* nop function */
void _nop(stack_t **head, unsigned int line_number)
{
	(void) head;
    (void) line_number;
}

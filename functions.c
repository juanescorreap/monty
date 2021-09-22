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
	stack_t *temp = *head;

	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/* pint function */
void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		printf("L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/* pop function */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *delete_node;

	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_node = *head;
	*head = delete_node->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(delete_node);
}
/* swap function */
void _swap(stack_t **head, unsigned int line_number)
{
	int i = (*head)->n;

	if ((*head)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->n = (*head)->next->n;
	(*head)->next->n = i;
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


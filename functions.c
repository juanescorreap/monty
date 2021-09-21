#include "monty.h"
/**
 * get_op_cases - Function converts numbers to char.
 * Return: Void.
 * @format: Sting being searched for %
 * @i: holds the place in which % was found in the string
 */
/* push function */
void _push(stack_t **head, unsigned int line_number)
{
}
/* pall function */
void _pall(stack_t **head, unsigned int line_number)
{
	int i = 0;

	while (*head)
	{
		printf("%d\n", *head->line_number);
		*head = *head->next;
		i++;
	}
	return (i);
}
/* pint function */
void _pint(stack_t **head, unsigned int line_number)
{
}
/* pop function */
void _pop(stack_t **head, unsigned int line_number)
{
}
/* swap function */
void _swap(stack_t **head, unsigned int line_number)
{
}
/* add function */
void _add(stack_t **head, unsigned int line_number)
{
}
/* nop function */
void _nop(stack_t **head, unsigned int line_number)
{
	(void) head;
    (void) line_number;
}

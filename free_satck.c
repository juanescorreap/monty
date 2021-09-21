#include "monty.h"
/**
 * get_op_cases - Function converts numbers to char.
 * Return: Void.
 * @format: Sting being searched for %
 * @i: holds the place in which % was found in the string
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

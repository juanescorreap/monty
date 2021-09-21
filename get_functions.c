#include "monty.h"
/**
 * get_op_cases - Function converts numbers to char.
 * Return: Void.
 * @format: Sting being searched for %
 * @i: holds the place in which % was found in the string
 **/
void(*get_functions())(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t array[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}};

	while (array[i].opcode != NULL)
	{
		if (strcmp(array[i].opcode, data.op_code) == 0)
		{
			return (array[i].f);
		}
		i++;
	}
	return (NULL);
}

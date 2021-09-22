#include "monty.h"
/**
 * get_functions - Function compares the opecode with an array
 * and returns the function that excutes it
 * Return: Void.
 **/
void (*get_functions())(stack_t **stack, unsigned int line_number)
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
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
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

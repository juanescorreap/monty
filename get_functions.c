#include "monty.h"
/**
 * get_op_cases - Function converts numbers to char.
 * Return: Void.
 * @format: Sting being searched for %
 * @i: holds the place in which % was found in the string
 */
void(*get_functions())
{
	int x = 0;

	instruction_t array[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}};

	while (array[x].opcode != NULL)
	{
		if (*array[x].opcode == format[i])
		{
			return (*array[x].function);
		}
		x++;
	}
	return (NULL);
}
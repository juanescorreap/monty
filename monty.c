#include "monty.h"
inputdata_t data = {NULL, NULL, NULL, NULL};
/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: Number of arguments passed through the command line
 * @argv: Array of strings containing the arguments
 * passed through the command line
 * Return: Integer denotating if success or not
 */
int main(int argc, char **argv)
{
	size_t buffersize = 0;
	unsigned int i;
	void (*op_code_handler)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		return (EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	data.pointer_to_file = fopen(argv[1], "r");
	for (i = 1; getline(&data.buffer, &buffersize, data.pointer_to_file)
	!= -1; i++)
	{
		data.op_code = strtok(data.buffer, DELIMITERS);
		if (data.op_code != NULL)
		{
			op_code_handler = get_functions();
			if (op_code_handler == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", i, data.op_code);
				return (EXIT_FAILURE);
			}
			op_code_handler(&data.stack, i);
		}
	}
	freedata(data);
	return (EXIT_SUCCESS);
}

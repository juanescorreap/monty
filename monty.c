#include "monty.h"
inputdata_t data = {NULL, NULL, NULL, NULL};
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
int main(int argc, char **argv)
{
	size_t buffersize = 0;
	unsigned int i;
	void (*op_code_handler)(stack_t **stack, unsigned int line_number);

	if(argc != 2)
	{
		printf("USAGE: monty %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	data.pointer_to_file = fopen(argv[1], "r");
	for (i = 1; getline(&data.buffer, &buffersize, data.pointer_to_file) != -1; i++)
	{
		data.op_code = strtok(data.buffer, DELIMITERS);
		if (data.op_code != NULL)
		{
			op_code_handler = get_functions();
			if (op_code_handler == NULL)
			{
				printf("Error: Can't open file %s\n", argv[2]);
				exit(EXIT_FAILURE);
			}
			op_code_handler(&data.stack, i);
		}
	}
	freedata(data);
	return (EXIT_SUCCESS);
}

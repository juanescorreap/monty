#include "monty.h"
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
	char *buffer = NULL;
	size_t buffersize = 0;
	FILE *pointer_to_file;
	int number_char_read;

	if(argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	pointer_to_file = fopen(argv[1], "r");
	number_char_read= getline(&buffer, &buffersize, pointer_to_file);
	while(number_char_read != -1)
	{
		strtok(buffer, " ");
	}
	return (0)
}
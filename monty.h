#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define DELIMITERS (" \n\t\v\f")
#define freedata(DATA)                          \
	do {                                    \
		free((DATA).buffer);            \
		free_stack((DATA).stack);       \
		fclose((DATA).pointer_to_file); \
	} while (0)

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct inputdata_s - Struct to store data
 * @op_code: the opcode
 * @buffer: Array that stores the line read by getline
 * @pointer_to_file: Pointer to file where the opcodes are written
 * @stack: Head to the double linked list being used
 * Description: Struct to store data
 */
typedef struct inputdata_s
{
	char *op_code;
	char *buffer;
	FILE *pointer_to_file;
	stack_t *stack;
} inputdata_t;

/* Global function*/
extern inputdata_t data;

/* push function */
void _push(stack_t **head, unsigned int line_number);
/* pall function */
void _pall(stack_t **head, unsigned int line_number);
/* pint function */
void _pint(stack_t **head, unsigned int line_number);
/* pop function */
void _pop(stack_t **head, unsigned int line_number);
/* swap function */
void _swap(stack_t **head, unsigned int line_number);
/* add function */
void _add(stack_t **head, unsigned int line_number);
/* nop function */
void _nop(stack_t **head, unsigned int line_number);

/*number_verifier function*/
int number_verifier(char *string);
/*free_stack function*/
void free_stack(stack_t *head);
/*get_functions function*/
void (*get_functions())(stack_t **stack, unsigned int line_number);
#endif

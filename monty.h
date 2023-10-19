#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **all_op_tokens;

#define DELIMS " \n\t"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Error messages found in file error_messages1.c*/
int arg_not_2_error(void);
int file_error(char *filename);
int malloc_free_error(void);
int unknown_op_func_error(char *opcode, unsigned int line_n);
int no_int_error(unsigned int line_n);

/*Error messages found in file error_messages2.c*/
void set_op_tok_error(int exit_s);
int pint_error(unsigned int line_n);
int pint_error(unsigned int line_n);
int pop_error(unsigned int line_n);
int swapError(unsigned int line_n);

/*Error messages found in file error_messages3.c*/
int addError(unsigned int line_n);

/*Change interger to string functions in function3.c*/
char *change_int_str(int num);

int execute_monty(FILE *file);

/*functions that are part of monty.c is found in functions1.c*/
int is_empty_line(char *line, char *delims);
int init_stack(stack_t **stack);
void free_stack(stack_t **stack);
void free_op_tokens(void);
int check_mode(stack_t *stack);

unsigned int token_arr_len(void);

/*functions that are part of monty operation is found in functions2.c*/
int is_valid_int(void);



char **strtow(char *str, char *delims);

/*First Opcodes found in monty_operations1.c*/
void push_to_stack(stack_t **stack, unsigned int line_n);
void print_all_stack(stack_t **stack, unsigned int line_n);
void print_top_stack_pint(stack_t **stack, unsigned int line_n);
void pop_from_stack(stack_t **stack, unsigned int line_n);
void swap_top_2(stack_t **stack, unsigned int line_n);

/*First Opcodes found in monty_operations2.c*/
void add_top_2(stack_t **stack, unsigned int line_n);
void does_nothing(stack_t **stack, unsigned int line_n);




#endif

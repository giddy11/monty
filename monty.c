#define _POSIX_C_SOURCE 200809L  /* Define this macro for getline*/

#include "monty.h"

char **all_op_tokens = NULL;

/**
 * main - Entry point.
 * @argc: The number of arguments used to execute the program.
 * @argv: An array of strings (arguments used to run the program).
 *
 * Return: 0, on success.
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	int exit_s = EXIT_SUCCESS;

	if (argc != 2)
		return (arg_not_2_error());

	file = fopen(argv[1], "r");
	if (file == NULL)
		return (file_error(argv[1]));

	exit_s = execute_monty(file);

	fclose(file);

	return (exit_s);
}

/**
 * get_op_function - matches an opcodes	with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_function(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_and_funcs[] = {
		{"push", push_to_stack},
		{"pall", print_all_stack},
		{"pint", print_top_stack_pint},
		{"pop", pop_from_stack},
		{"swap", swap_top_2},
		{"add", add_top_2},
		{"nop", does_nothing},
		{"sub", sub_top_2},
		{"div", div_top_2},
		{"mul", mul_top_2},
		{"mod", mod_top_2},
		{NULL, NULL}};

	int i;

	for (i = 0; op_and_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_and_funcs[i].opcode) == 0)
			return (op_and_funcs[i].f);
	}

	return (NULL);
}

/**
 * token_arr_len - gets the length of all_op_tokens.
 *
 * Return: Length of current all_op_tokens.
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (all_op_tokens[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * execute_monty - runs the bytecode on each line.
 * @file: Pathname of the file containing bytecode.
 *
 * Return: EXIT_SUCCESS on success,
 *		respective error code on failure.
 */
int execute_monty(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_s = EXIT_SUCCESS;
	unsigned int line_n = 0, prev_tok_len = 0;
	void (*op_function)(stack_t **, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, file) != -1)
	{
		line_n++;
		all_op_tokens = strtow(line, DELIMS);
		if (all_op_tokens == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_free_error());
		}
		else if (all_op_tokens[0][0] == '#')
		{
			free_op_tokens();
			continue;
		}
		op_function = get_op_function(all_op_tokens[0]);
		if (op_function == NULL)
		{
			free_stack(&stack);
			exit_s = unknown_op_func_error(all_op_tokens[0], line_n);
			free_op_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_function(&stack, line_n);
		if (token_arr_len() != prev_tok_len)
		{
			if (all_op_tokens && all_op_tokens[prev_tok_len])
				exit_s = atoi(all_op_tokens[prev_tok_len]);
			else
				exit_s = EXIT_FAILURE;
			free_op_tokens();
			break;
		}
		free_op_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_free_error());
	}
	free(line);
	return (exit_s);
}

#include "monty.h"

/**
 * set_op_tok_error - sets last element of all_op_tokens to be an exit status.
 * @exit_status: Integer to store as a string in all_op_tokens.
 */
void set_op_tok_error(int exit_status)
{
	int num_of_token = 0;
	int i = 0;
	char *exit_status_str = NULL;
	char **new_tokens = NULL;

	num_of_token = token_arr_len();
	new_tokens = malloc(sizeof(char *) * (num_of_token + 2));
	if (all_op_tokens == NULL)
	{
		malloc_free_error();
		return;
	}
	while (i < num_of_token)
	{
		new_tokens[i] = all_op_tokens[i];
		i++;
	}
	exit_status_str = change_int_str(exit_status);
	if (exit_status_str == NULL)
	{
		free(new_tokens);
		malloc_free_error();
		return;
	}
	new_tokens[i] = exit_status_str;
	i++;
	new_tokens[i] = NULL;
	free(all_op_tokens);
	all_op_tokens = new_tokens;
}

/**
 * pint_error - prints the error message for can't pint, stack empty.
 * @line_n: Line number in Monty bytecode file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_n)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
	return (EXIT_FAILURE);
}

/**
 * pop_error - prints the error message for can't pop an empty stack.
 * @line_n: Line number in Monty bytecode file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_n)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
	return (EXIT_FAILURE);
}

#include "monty.h"

/**
 * is_empty_line - checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * init_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an uninitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = 0;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * free_op_tokens - frees all tokens in array of tokens.
 */
void free_op_tokens(void)
{
	size_t i = 0;

	if (all_op_tokens == NULL)
		return;

	for (i = 0; all_op_tokens[i]; i++)
		free(all_op_tokens[i]);

	free(all_op_tokens);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - 0.
 *         If the stack_t is in queue mode - 1.
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == 0)
		return (0);
	else if (stack->n == 1)
		return (1);
	return (2);
}

#include "monty.h"

/**
 * add_top_2 - a function to add the top two elements of a stack.
 * @stack: Double pointer to the head of the list.
 * @line_n: The line the add opcode was called from.
 */
void add_top_2(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = (*stack)->next;

	if (tmp == NULL || tmp->next == NULL)
	{
		set_op_tok_error(addError(line_n));
		return;
	}
	tmp->next->n = tmp->next->n + tmp->n;
	pop_from_stack(stack, line_n);
}

/**
 * does_nothing - A placeholder function that does nothing.
 * @stack: Unused parameter.
 * @line_n: Unused variable.
 */
void does_nothing(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}

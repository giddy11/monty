#include "monty.h"

/**
 * mod_top_2 - computes the remainder from the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: Double pointer to the head of the list.
 * @line_n: The line the mod opcode was called from.
 */
void mod_top_2(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = (*stack)->next;

	if (tmp == NULL || tmp->next == NULL)
	{
		set_op_tok_error(short_stackErrors(line_n, "mod"));
		return;
	}
	if (tmp->n == 0)
	{
		set_op_tok_error(divError(line_n));
		return;
	}

	tmp->next->n %= tmp->n;
	pop_from_stack(stack, line_n);
}

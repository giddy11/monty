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

/**
 * sub_top_2 - subtracts the top element of a stack from the second top.
 * @stack: Double pointer to the head of the list
 * @line_n: The line the sub opcode was called from.
 *
 */
void sub_top_2(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = (*stack)->next;

	if (tmp == NULL || tmp->next == NULL)
	{
		set_op_tok_error(short_stackErrors(line_n, "sub"));
		return;
	}
	tmp->next->n -= tmp->n;
	pop_from_stack(stack, line_n);
}

/**
 * div_top_2 - divides the second top element of the stack by the top element of the stack.
 * @stack: Double pointer to the head of the list.
 * @line_n: The line the div opcode was called from.
 */

void div_top_2(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = (*stack)->next;

	if (tmp == NULL || tmp->next == NULL)
	{
		set_op_tok_error(short_stackErrors(line_n, "div"));
		return;
	}
	if (tmp->n == 0)
	{
		set_op_tok_error(divError(line_n));
		return;
	}

	tmp->next->n /= tmp->n;
	pop_from_stack(stack, line_n);
}

#include "monty.h"

/**
 * mul_top_2 - multiplies the top two elements of a stack.
 * @stack: Double pointer to the head of the list.
 * @line_n: The line the mul opcode was called from.
 */
void mul_top_2(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = (*stack)->next;

	if (tmp == NULL || tmp->next == NULL)
	{
		set_op_tok_error(short_stackErrors(line_n, "mul"));
		return;
	}
	tmp->next->n *= tmp->n;
	pop_from_stack(stack, line_n);
}

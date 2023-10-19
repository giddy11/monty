#include "monty.h"

/**
 * push_to_stack - pushes an integer to a stack.
 * @stack: A pointer to the top (mode node) of a stack.
 * @line_n: The line the push opcode was called from.
 */
void push_to_stack(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp, *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		malloc_free_error();
		set_op_tok_error(EXIT_FAILURE);
		return;
	}
	if (all_op_tokens[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_n));
		return;
	}
	if (is_valid_int() == 0)
	{
		set_op_tok_error(no_int_error(line_n));
		return;
	}
	newNode->n = atoi(all_op_tokens[1]);
	if (check_mode(*stack) == 0) /* STACK mode insert at the front */
	{
		tmp = (*stack)->next;
		newNode->prev = *stack;
		newNode->next = tmp;
		if (tmp)
			tmp->prev = newNode;
		(*stack)->next = newNode;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newNode;
		newNode->prev = tmp;
		newNode->next = NULL;
	}
}

/**
 * print_all_stack - prints the stack (value).
 * @stack: Double pointer to the head of the list.
 * @line_n: The line the opcode was called from.
 */
void print_all_stack(stack_t **stack, unsigned int line_n)
{
	stack_t *temp = *stack;

	(void)line_n;

	temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * print_top_stack_pint - prints the value at the top of the stack.
 * @stack: Double pointer to the head of the list.
 * @line_n: The line the opcode was called from.
 */
void print_top_stack_pint(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = *stack;

	tmp = tmp->next;
	if (tmp == NULL)
	{
		set_op_tok_error(pint_error(line_n));
		return;
	}
	printf("%d\n", tmp->n);
}

/**
 * pop_from_stack - pops the value at the top of the stack.
 * @stack: Double pointer to the head of the list.
 * @line_n: The line the pop opcode was called from.
 */

void pop_from_stack(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp = NULL, *tmp2 = NULL;

	tmp = (*stack)->next;
	if (tmp == NULL)
	{
		set_op_tok_error(pop_error(line_n));
		return;
	}
	tmp2 = tmp->next;
	free(tmp);
	(*stack)->next = tmp2;
	if (tmp2)
		tmp2->prev = (*stack);
}

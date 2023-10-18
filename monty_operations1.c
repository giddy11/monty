#include "monty.h"

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecode file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * push_to_stack - pushes an integer to a stack.
 * @stack: A pointer to the top (mode node) of a stack.
 * @line_number: The line the push opcode was called from.
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
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
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	if (is_valid_int() == 0)
	{
		set_op_tok_error(no_int_error(line_number));
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
	/* else  QUEUE mode insert at the end */
}

/**
 * print_all_stack - prints the stack (value).
 * @stack: Double pointer to the head of the list.
 * @line_number: The line the opcode was called from.
 */
void print_all_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

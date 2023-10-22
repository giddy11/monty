#include "monty.h"

/**
 * addError - prints the error message for stack too short to add.
 * @line_n: Line number in Monty bytecode file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int addError(unsigned int line_n)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
	return (EXIT_FAILURE);
}

/**
 * short_stackErrors - prints the error message for different functions.
 * @line_n: Line number in Monty bytecode file where error occurred.
 * @error: The error message to be printed.
 * Return: (EXIT_FAILURE) always.
 */
int short_stackErrors(unsigned int line_n, char *error)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", line_n, error);
	return (EXIT_FAILURE);
}

/**
 * divError - prints the error message for top stack equal to 0.
 * @line_n: Line number in Monty bytecode file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int divError(unsigned int line_n)
{
	fprintf(stderr, "L%d: division by zero\n", line_n);
	return (EXIT_FAILURE);
}


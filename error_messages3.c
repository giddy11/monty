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

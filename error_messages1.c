#include "monty.h"

/**
 * arg_not_2_error - Prints the usage error messages.
 */
 int arg_not_2_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_error - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open.
 */
int file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * malloc_free_error - Prints malloc error messages.
 */
int malloc_free_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * unknown_op_func_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecode file where error occurred.
 */
int unknown_op_func_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

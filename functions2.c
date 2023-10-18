#include "monty.h"

/**
 * is_valid_int - checks if a string can
 *					be made into a valid integer.
 * Return: 1, if it can be a valid integer
 * 			else 0.
 */
int is_valid_int(void)
{
	int i;

	for (i = 0; all_op_tokens[1][i]; i++)
	{
		if (i == 0 && all_op_tokens[1][i] == '-')
			continue;
		if (all_op_tokens[1][i] < '0' || all_op_tokens[1][i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

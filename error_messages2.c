#include "monty.h"

char *change_int_str(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
					   char *buff, int buff_size);

/**
 * change_int_str - gets a character pointer to new string containing int.
 * @num: Number to be converted to string
 *
 * Return: On Success, character pointer to newly created string,
 * 						NULL if malloc fails.
 */
char *change_int_str(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret_string;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret_string = malloc(length + 1);
	if (!ret_string)
		return (NULL);

	fill_numbase_buff(temp, 10, ret_string, length);
	if (num < 0 || num_l < 0)
		ret_string[0] = '-';

	return (ret_string);
}

/**
 * _abs - gets the absolute value of an integer.
 * @i: The integer to get absolute value of.
 *
 * Return: Unsigned integer abs representation of @i.
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int.
 * @num: Number to get length needed for.
 * @base: Base of number representation used by buffer.
 *
 * Return: Integer containing length of buffer needed (excluding null bytecode).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36.
 * @num: Number to convert to string given base.
 * @base: Base of number used in conversion, only works up to base 36.
 * @buff: Buffer to fill with result of conversion.
 * @buff_size: The size of buffer in bytes.
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
					   char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)			/* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

/**
 * set_op_tok_error - sets last element of all_op_tokens to be an exit status.
 * @exit_status: Integer to store as a string in all_op_tokens.
 */
void set_op_tok_error(int exit_status)
{
	int num_of_token = 0;
	int i = 0;
	char *exit_status_str = NULL;
	char **new_tokens = NULL;

	num_of_token = token_arr_len();
	new_tokens = malloc(sizeof(char *) * (num_of_token + 2));
	if (all_op_tokens == NULL)
	{
		malloc_free_error();
		return;
	}
	while (i < num_of_token)
	{
		new_tokens[i] = all_op_tokens[i];
		i++;
	}
	exit_status_str = change_int_str(exit_status);
	if (exit_status_str == NULL)
	{
		free(new_tokens);
		malloc_free_error();
		return;
	}
	new_tokens[i] = exit_status_str;
	i++;
	new_tokens[i] = NULL;
	free(all_op_tokens);
	all_op_tokens = new_tokens;
}

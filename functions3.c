#include "monty.h"

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

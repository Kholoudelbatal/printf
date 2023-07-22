#include "main.h"

/**
 * is_printable - selection char printable
 * @c: char
 *
 * Return: 1 when c is printable, 0 if not
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * is_digit - selection char is a digit
 * @c: char
 *
 * Return: 1 when c is a digit, 0 if not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: number to be printed
 * @size: number setting the type
 *
 * Return: printed value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - convert number to specified size
 * @num: number to be converted
 * @size: number setting type
 *
 * Return: converted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}


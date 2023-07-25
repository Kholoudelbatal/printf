#include "main.h"
/**
 * print_c - prints char
 * @list: arguments list
 * Return: number of printed chars
 */
int print_c(va_list list)
{
	put_char(va_arg(list, int));
	return (1);
}

/**
 * print_str - print string
 * @list: arguments list
 * Return: number of printed chars
 */
int print_str(va_list list)
{
	int s;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (s = 0; str[s] != '\0'; s++)
		put_char(str[s]);
	return (s);
}

/**
 * print_prcnt - prints percent sign
 * @list: arguments list
 * Return: number of printed chars
*/
int print_prcnt(__attribute__((unused))va_list list)
{
	put_char('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @list: arguments list
 * Return: number of printed chars
*/
int print_integer(va_list list)
{
	int num_length;

	num_length = print_num(list);
	return (num_length);
}


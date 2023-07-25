#include "main.h"
/**
 * _printf - function prints a formated string
 * @format: the string format
 * @...: number of variable arguments
 * Return: number of printed chars
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {
		{"c", print_c},
		{"s", print_str},
		{"%", print_prcnt},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	printed_chars = formater(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}

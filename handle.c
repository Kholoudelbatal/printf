#include "main.h"
/**
 * handle_format - handles different specifiers
 * @counter: the counter
 * @specifier: the specifier
 * @arg: argument
 */
void handle_format(va_list arg, char specifier, int *counter)
{
	switch (specifier)
	{
		case 'c':
				(*counter) += _putchar(va_arg(arg, int));
				break;
		case 's':
				(*counter) += put_string(va_arg(arg, char *));
				break;
		case '%':
				(*counter) += _putchar('%');
				break;
		case 'i':
		case 'd':
				(*counter) += print_number(va_arg(arg, int));
				break;
		case 'b':
				(*counter) += print_binary(va_arg(arg, unsigned int));
				break;
		default:
				_putchar('%');
				_putchar(specifier);
				(*counter) += 2;
				break;
	}
}

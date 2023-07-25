#include "main.h"

int put_char(char c);

/**
 * _printf - function prints a formated string
 * @format: the string format
 * @...: number of variable arguments
 * Return: number of printed chars
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;

	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					{
						char c = (char)va_arg(args, int);

						put_char(c);
						printed_chars++;
						break;
					}

				case 's':
					{
						char *str = va_arg(args, char *);

					if (str == NULL)
						str = "(NULL)";

					for (; *str; str++)
					{
						put_char(*str);
						printed_chars++;
					}
					break;
					}

				case '%':
					put_char('%');
					printed_chars++;
					break;

				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						int digits = 0;
						int temp = num;

					if (num < 0)
					{
						put_char('-');
						printed_chars++;
						num = -num;
					}

					do {
						digits++;
						temp /= 10;
					} while (temp);
					temp = num;
					do {
						int digit = temp % 10;

						put_char('0' + digit);
						printed_chars++;
						temp /= 10;
					} while (--digits > 0);
					break;
					}

				default:
					put_char('%');
					put_char(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			put_char(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * put_char - prints char c to stdout
 * @c: the character to print
 * Return: On success 1
 *              On error, -1 is returned, and errno is set appropriately
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}


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

	while (*format)
	{
		if (*format == '%')
		{
			format++;

		switch (*format)
		{

			case 'c':
				put_char((char)va_arg(args, int));
				printed_chars++;
				break;

			case 's':
			{
				int l;
				char *st = va_arg(args, char *);

				if (st == NULL)
					st = "(NULL)";

				for (l = 0; st[l]; l++)
				{
					put_char(st[l]);
					printed_chars++;
				}
				break;

			}

			case '%':
				put_char('%');
				printed_chars++;
				break;
			case 'i':
			case 'd':
				{
					int m = va_arg(args, int);
					int x = 0;
					int temp = m;

					if (m < 0)
					{
						put_char('-');
						printed_chars++;
						m = -m;
					}

					do

					{
						x++;
						temp /= 10;
					}

					while (temp);
					temp = m;

					do

					{

						int digit = temp % 10;

						put_char('0' + digit);
						printed_chars++;
						temp /= 10;
					} while (--x > 0);
					break;

			default:

				put_char('%');
				put_char(*format);
				printed_chars += 2;
				break;
				}
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
 *              On error, -1 is returned, and errno iss set appropriatly
*/
int put_char(char c)
{
	return (write(1, &c, 1));
}


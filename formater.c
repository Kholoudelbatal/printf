#include "main.h"
/**
 * formater - analyize specifiers to format a sting
 * @format: string formated
 * f_list: functions list
 * arg_list: arguments list
 * Return: number of printed characters
*/
int formater(const char *format, conver_t f_list[], va_list arg_list)
{
	int ind, x, r_val, printed_chars;

	printed_chars = 0;
	for (ind = 0; format[ind] != '\0'; ind++)
	{
		if (format[ind] == '%')
		{

			for (x = 0; f_list[x].sym != NULL; x++)
			{
				if (format[ind + 1] == f_list[x].sym[0])
				{
					r_val = f_list[x].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[x].sym == NULL && format[ind + 1] != ' ')
			{
				if (format[ind + 1] != '\0')
				{
					put_char(format[ind]);
					put_char(format[ind + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			ind = ind + 1;
		}
		else
		{
			put_char(format[ind]);
			printed_chars++;
		}
	}
	return (printed_chars);
}

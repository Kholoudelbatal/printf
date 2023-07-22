#include "main.h"
/**
 * print_percent - prints percent sign
 * @types: arguments
 * @buffer: array to handle print
 * @flags: format flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of bytes printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


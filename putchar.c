#include "main.h"

/**
 * put_char - prints char to stdout
 * @c: char
 * Return: On success 1
 *              On error, -1 is returned, and errno is set appropriately
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}

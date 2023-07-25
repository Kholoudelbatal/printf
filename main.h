#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
/**
 * struct convert - structure for symbols and functions
 *
 * @sym: symbol
 * @f: related function
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;


int formater(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int put_char(char);
int print_c(va_list);
int print_str(va_list);
int print_prcnt(va_list);
int print_integer(va_list);
int print_num(va_list);

#endif

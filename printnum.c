#include "main.h"
/**
 * print_num - print number
 * @args: arguments
 * Return: number of printed chars
 */
int print_num(va_list args)
{
        int n;
        int v;
        int l;
        unsigned int num;

        n  = va_arg(args, int);
        v = 1;
        l = 0;

        if (n < 0)
        {
                l += put_char('-');
                num = n * -1;
        }
        else
                num = n;

        for (; num / v > 9; )
                v *= 10;

        for (; v != 0; )
        {
                l += put_char('0' + num / v);
                num %= v;
                v /= 10;
        }

        return (l);
}

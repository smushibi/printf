#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - Custom printf implementation
 * @format: The format string with conversion specifiers
 * @...: Variable arguments based on conversion specifiers
 *
 * Return: The number of printed characters (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
char c;
const char *s;
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
c = (char) va_arg(args, int);
putchar(c);
count++;
break;
case 's':
s = va_arg(args, const char *);
while (*s)
{
putchar(*s);
s++;
count++;
}
break;
case '%':
putchar('%');
count++;
break;
default:
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}

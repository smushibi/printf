#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - Custom printf implementation
 * @format: Format string with conversion specifiers
 * @...: Variable arguments based on conversion specifiers
 * Return: Number of printed characters (excluding null byte)
 */
int _printf(const char *format, ...)
{
int count;
const char *s;
va_list args;
va_start(args, format);
count = 0;
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
int c = va_arg(args, int);
count += putchar(c);
}
else if (*format == 's')
{
s = va_arg(args, const char *);
while (*s)
{
count += putchar(*s);
s++;
}
}
else if (*format == '%')
{
count += putchar('%');
}
}
else
{
count += putchar(*format);
}
format++;
}
va_end(args);
return (count);
}

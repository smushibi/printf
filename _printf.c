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
va_list args;
va_start(args, format);
int count = 0;
for (; *format; format++)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
{
const char *s = va_arg(args, const char *);
for (; *s; s++)
count += putchar(*s);
break;
}
case '%':
count += putchar('%');
break;
default:
break;
}
}
else
{
count += putchar(*format);
}
}
va_end(args);
return (count);
}

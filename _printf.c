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
int len = 0;
va_list args;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
len += putchar(va_arg(args, int));
break;
case 's':
{
char *str = va_arg(args, char *);
while (*str != '\0')
{
len += putchar(*str);
str++;
}
break;
}
case 'd':
case 'i':
len += printf("%d", va_arg(args, int));
break;
case 'u':
len += printf("%u", va_arg(args, unsigned int));
break;
case 'o':
len += printf("%o", va_arg(args, unsigned int));
break;
case 'x':
case 'X':
len += printf("%x", va_arg(args, unsigned int));
break;
case 'p':
len += printf("%p", va_arg(args, void *));
break;
case '%':
len += putchar('%');
break;
default:
len += putchar('%');
len += putchar(*format);
break;
}
}
else
{
len += putchar(*format);
}
format++;
}
va_end(args);
return (len);
}

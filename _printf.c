#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Arguments to format
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
int count;
va_list args;
va_start(args, format);
count = vprintf(format, args);
va_end(args);
return (count);
}

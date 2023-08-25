#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

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
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
putchar(va_arg(args, int));
}
else if (*format == 's')
{
const char *s = va_arg(args, const char *);
while (*s)
{
putchar(*s);
s++;
}
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
if (num < 0)
{
putchar('-');
num = -num;
}
if (num == 0)
{
putchar('0');
}
while (num)
{
int digit = num % 10;
putchar('0' + digit);
num /= 10;
}
}
else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
{
unsigned int num = va_arg(args, unsigned int);
if (num == 0)
{
putchar('0');
}
const char *digits = (*format == 'u') ? "0123456789" : (*format == 'o') ? "01234567" : "0123456789abcdef";
int base = (*format == 'X') ? 16 : (*format == 'o') ? 8 : 10;
char buffer[12];
int idx = 0;
while (num)
{
buffer[idx++] = digits[num % base];
num /= base;
}
for (int i = idx - 1; i >= 0; i--)
{
putchar(buffer[i]);
}
}
else if (*format == 'p')
{
putchar('0');
putchar('x');
unsigned long long ptr_num = (unsigned long long)va_arg(args, void *);
for (int i = sizeof(void *) * 2 - 1; i >= 0; i--)
{
int hex_digit = (ptr_num >> (i * 4)) & 0xF;
putchar(hex_digit < 10 ? '0' + hex_digit : 'a' + hex_digit - 10);
}
}
else if (*format == '%')
{
putchar('%');
}
else
{
putchar('%');
putchar(*format);
}
count++;
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

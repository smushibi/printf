#include "main.h"
/**
 * _printf -a function to produce output according to the format
 * @format: character string
 * @...: variables
 * Return: the number of character printed
 */
int _printf(const char *format, ...)
{
	int ch = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ch++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				ch++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list, int);
				write(1, &c, 1);
				ch++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
				{
					str_len++;
				}
				write(1, str, str_len);
				ch += str_len;
			}
		}
		format++;
	}
	va_end(list);

	return (ch);
}
int main(void)
{
	_printf("Caro\n");
	_printf("%c\n", 'I');
	_printf("%s\n", "String");
	_printf("%%\n");
	return (0);
}

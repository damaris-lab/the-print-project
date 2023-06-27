#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - prints items based on format
 * @format: the format specifier
 * Return: pointer to index
 */
int _printf(const char *format, ...)
{
	va_list list;
	int count = 0;

	va_start(list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(list, int);

				_putchar(c);
				count++;
			}
			if (*format == 's')
			{
				char *str = va_arg(list, char*);

				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(list);
	return (count);
}


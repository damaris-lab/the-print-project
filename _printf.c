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

	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'c')
			{
				int c = va_arg(list, int);

				putchar(c);
				++count;
			}
			else if (*format == 's')
			{
				const char *s = va_arg(list, const char*);

				while (*s)
				{
					putchar(*s++);
					++count;
				}
			}
		else
		{
			putchar(*format);
			++count;
		}
		++format;
		}
	}
	va_end(list);
	return (count);
}


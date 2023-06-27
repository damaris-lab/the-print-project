#include "main.h"

/**
 * _printf - prints items based on format
 * @format: the format specifier
 * Return: pointer to index
 */
int _printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);

	while (*format)
	{
		if (*format == '%')
		{
			++format;
			switch (*format)
			{
				case 'c':
					{
						char ch = va_arg(list, int);
						putchar(ch);
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(list, int);
						printf("%d", num);
						break;
					}
				case 's':
					{
						char *str = va_arg(list, char*);
						puts(str);
						break;
					}
				case 'x':
					{
						int num = va_arg(list, int);
						printf("0x%x", num);
						break;
					}
				default:
					putchar(*format);
					break;
			}
		}
		else
		{
			putchar(*format);
		}
		++format;
	}
	va_end(list);
}


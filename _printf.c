#include "main.h"
/**
 * _printf - print all
 * @format: format to print
 * Return: 0(success)
 */
int _printf(cont char *format, ...)
{
	va_list list;
	unsigned int x = 0, y = 0, counter = 0;
	unsigned int flag;
	type_t types[] = {
		{"%", _print_mod}, {"c", _print_char}, {"s", _print_string},
		{"d", _print_int}, {"i", _print_int}, {"r", _print_reverse},
		{"R", _print_rot13}, {NULL, NULL}
	};

	va_start(list, format);
	if (format == NULL || (format[y] == '%' && format[y] == '\0'))
		return (0);
	while (format[y] != '\0')
	{
		flag = 0;
		if (format[y] == '%')
		{
			x = 0;
			while (types[x].identifier != NULL && flag == 0)
			{
				if (*(types[x].identifier) == format[y + 1])
				{
					counter += (types[x].function(list));
					flag = 1;
				}
				else
					x++;
			}
			if (types[x].identifier == NULL)
			{
				_putchar(format[y]);
				counter += 1;
				_putchar(format[y + 1]);
				counter += 1;
			}
			y = y + 2;
		}
		else
		{
			_putchar(format[y]);
			counter += 1;
			y++;
		}
	}
	va_end(list);
	return (counter);
}


#include "main.h"
/**
 * _printf - print all
 * @format: format to print
 * Return: 0(success)
 */
int _printf(const char *format, ...)
{
	int i, var;
	buffer *buf;
	va_list list;

	buf = buf_new();
	if (buf == NULL)
		return (-1);
	if (format == NULL)
		return (-1);
	va_start(list, format);
	i = var = 0;

	while (format[i])
	{
		buf_wrt(buf);
		if (format[i] == '%')
		{
			var = operation(buf, list, format, i);
			if (var < 0)
			{
				i = var;
				break;
			}
			i += var;
			continue;
		}
		buf->str[buf->index] = format[i];
		buf_increment(buf);
		i++;
	}
	buf_write(buf);
	va_end(list);
	return (i);
}


#include "main.h"
/**
 * _printf - print all
 * @format: format to print
 * Return: 0(success)
 */
int _printf(const char *format, ...)
{
	int i = 0, var = 0;
	va_list list;
	buffer *buf;

	buf = buf_new();
	if (buf == NULL && format == NULL)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		buf_write(buf);
		if (format[i] == '%')
		{
			var = view_operation(buf, list, format, i);
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
	write_buffer(buf);
	if (var <= 0)
		i = buf->overflow;
	end_buffer(buf);
	va_end(list);
	return (i);
}


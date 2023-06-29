#include "main.h"
/**
 * view_operation - scans for the string operator
 * @list: arguments
 * @buf: pointer to buffer
 * @str: string to scan
 * @index: index where identifier is
 * Return: counter
 */
int view_operation(buffer *buf, va_list list, const char *str, int index)
{
	int j, k, fin = 0;
	type_t oper[] = {
		{"c", _print_char}, {"s", _print_string},
		{"%", _print_mod}, {"d", _print_int},
		{"i", _print_int}, {"h", NULL},
		{" ", NULL}, {"x", NULL},
		{"b", NULL}, {NULL, NULL}
	};

	for (j = 1; str[j + index]; j++)
	{
		for (k = 0; oper[k].identifier; k++)
		{
			if (str[j + index] == *(oper[k].identifier))
			{
				if (fin == 1)
					return (j + 1);
			}
		}
		if (oper[k].identifier == NULL && str[j + index])
		{
			buf->str[buf->index] = str[index];
			buf_increment(buf);
			return (1);
		}
	}
	if (str[j + index] == '\0')
	{
		buf->str[buf->index] = str[index + j];
		return (-1);
	}
	return (j);
}


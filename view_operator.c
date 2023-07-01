#include "main.h"
/**
 * operation - scans for the string operator
 * @list: arguments
 * @buf: pointer to buffer
 * @str: string to scan
 * @index: index where identifier is
 * Return: counter
 */
int operation(buffer *buf, va_list list, const char *src, int src_index)
{
	int j, k, count = 0;
	type_t array[] = {
		{"c", print_char}, {"s", print_string},
		{"%", print_mod}, {"d", print_int},
		{"i", print_int}, {"h", NULL},
		{"x", NULL}, {"b", write_binary},
		{"r", NULL},
		{NULL, NULL}
	};

	for (j = 1; src[j + src_index]; j++)
	{
		for (k = 0; array[k].identifier; k++)
		{
			if (src[j + src_index] == *(array[k].identifier))
			{
				if (array[k].function != NULL)
					count = array[k].function(buf, list);
				else
					break;
				if (count == 1)
					return (j + 1);
			}
		}
		if (array[k].identifier == NULL && src[j + src_index])
		{
			buf->str[buf->index] = src[src_index];
			buf_increment(buf);
			return (1);
		}
	}
	if (src[j + src_index] == '\0')
	{
		buf->str[buf->index] = src[src_index + j];
		return (-1);
	}
	return (j);
}


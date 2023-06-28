#include "main.h"
#include <stdarg.h>

/**
 *_prints - prints a character
 *@arg:no of arguement
 *@va_list:pointer variable
 * Return:count
 */
int _prints(va_list, arg)
{
	conversio m = {
	{"%i", printf_int}, {"%d", printf_dec},
	{"%c", printf_char}, {"%s", printf_string},
	{"%%", printf_37},
	{"%p", printf_pointer},
};

	char *str;
	int count, count = 0;
	int i, i = 0;


	str = var_arg(char *str, arg)
	while (str[i])
	{
		putchar (str[i];
		count++;
		i++;
	}
	return (count);

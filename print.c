#include "main.h"
#include <stdarg.h>

/**
 *_prints - prints a character
 *@arg::no of arguement
 * Return:count
 */
int _prints(va_list arg)
{
	char *str;
	int count;
	int i;

	i = 0;
	count = 0;

	str = va_arg(arg, char *);
	while (str[i])
	{
		_putchar(str[i]);
		count++;
		i++;
	}
		return (count);
}

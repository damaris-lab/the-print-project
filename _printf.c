#include "main.h"

/**
 * _printf - prints items based on format
 * @format: the format specifier
 * Return: pointer to index
 */
int _printf(const char *format, ...)
{
	va_list list;
	int text;

	va_start(list, format);
	text = vfprintf(stdout, format, list);
	va_end(arg);

	return (text);
}



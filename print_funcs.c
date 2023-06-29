#include "main.h"
/**
 * _print_mod - prints percet sign
 * @list: arguments
 * Return: counter
 */
int _print_mod(va_list list)
{
	int counter = 0;

	va_arg(list, int);
	_putchar('%');
	counter ++;
	return (counter);
}
/**
 * _print_string - prints strings
 * @list: arguments
 * Return: counter
 */
int _print_string(va_list list)
{
	int counter = 0;
	char *str = va_arg(list, char*);
	int x = 0;

	while (str[x])
	{
		_putchar(str[x]);
		counter ++;
		x++;
	}
	return (counter);
}
/**
 * _print_char - print characters
 * @list: arguments
 * Return: counter
 */
int _print_char(va_list list)
{
	int counter = 0;
	char str = (char)va_arg(list, int);

	_putchar(str);
	counter++;
	return (counter);
}
/**
 * _print_int - converts string to int
 * @list: arguments
 * Return: integers
 */
int _print_int(va_list list)
{
	int i, num = 0, counter = 0;
 	int n = va_arg(list, int);
	int max = 1000000000;

	if (n < 0)
	{
		_putchar('-');
		counter++;
	}
	if (n == 0)
	{
		_putchar('0');
		counter++;
	}
	for (i = 0; i < 10; i++)
	{
		if(n / max != 0)
		{
			num = (n / max) % 10;
			if (num < 0)
			{
				num *= -1;
			}
			_putchar(num + '0');
			counter++;
		}
		max /= 10;
	}
	return (counter);
}


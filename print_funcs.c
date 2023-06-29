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
		counter++;
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
/**
 * write_binary - converts digits to binary
 * @buf: pointer to a buffer
 * @list: arguments
 * Return: 1
 */
int write_binary(buffer *buf, va_list list)
{
	int i = 0;
	unsigned int num = va_arg(list, int);
	char array[100] = {'\0'};

	if (num == 0)
	{
		buf->str[buf->index] = '0';
		buf_increment(buf);
	}
	while (num > 0)
	{
		array[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}
	while (i--)
	{
		write_buffer(buf);
		buf->str[buf->index] = array[i];
		buf_increment(buf);
	}
	return (1);
}
/**
 * _print_rev - print string in reverse
 * @list: arguments
 * Return: counter
 */
int _print_rev(va_list list)
{
	char *str = va_arg(list, char*);
	int x, counter = 0;

	if (str == NULL)
		str = "(nil)";
	for (x = 0; str[x] != '\0'; x++)
		;
	for (x -= 1; x >= 0; x--)
	{
		_putchar(str[x]);
		counter++;
	}
	return (counter);
}
/**
 * _print_rot13 - encodes string in rot13
 * @list: arguments
 * Return: counter
 */
int _print_rot13(va_list list)
{
	char *x = va_arg(list, char*);
	int a, b, counter = 0;
	char forward[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rotate[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (a = 0; x[a] != '\0'; a++)
	{
		for (b = 0; forward[b] != '\0'; b++)
		{
			if (forward[b] == x[a])
			{
				_putchar(rotate[b]);
				counter++;
				break;
			}
		}
		if (forward[b] == '\0')
		{
			_putchar(x[a]);
			counter++;
		}
	}
	return (counter);
}


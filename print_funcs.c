#include "main.h"

/**
 * write_binary - convert digit to binary
 * @buf: pointer to buffer
 * @list: arguments
 * Return: int
 */
int write_binary(buffer *buf, va_list list)
{
	int i = 0;
	unsigned int temp = va_arg(list, int);
	char array[100] = {'\0'};

	if (temp == 0)
	{
		buf->str[buf->index] = '0';
		buf_increment(buf);
	}
	while (temp > 0)
	{
		array[i] = (temp % 2) + '0';
		temp /= 2;
		i++;
	}
	while (i--)
	{
		buf_wrt(buf);
		buf->str[buf->index] = array[i];
		buf_increment(buf);
	}
	return (1);
}
/**
 * print_char - prints characters
 * @buf: pointer to buffer
 * @list: arguments
 * Return: int
 */
int print_char(buffer *buf, va_list list)
{
	char temp = va_arg(list, int);

	buf_wrt(buf);
	buf->str[buf->index] = temp;
	buf_increment(buf);
	buf->str[buf->index] = '\0';
	return (1);
}
/**
 * print_string - prints strings
 * @buf: pointer to buffer
 * @list: arguments
 * Return: int
 */
int print_string(buffer *buf, va_list list)
{
	int i;
	char *temp = va_arg(list, char*);

	if (temp == NULL)
		temp = "(nil)";
	for (i = 0; temp[i]; i++)
	{
		buf_wrt(buf);
		buf->str[buf->index] = temp[i];
		buf_increment(buf);
	}
	buf->str[buf->index] = '\0';
	return (1);
}
/**
 * print_int - prints integers
 * @buf: pointer to buffer
 * @list: arguments
 * Return: int
 */
int print_int(buffer *buf, va_list list)
{
	int temp = va_arg(list, int);
	unsigned int num = temp;

	if (temp == 0)
	{
		buf->str[buf->index] = '0';
		buf_increment(buf);
		return (1);
	}
	else if (temp < 0)
	{
		buf->str[buf->index] = '-';
		buf_increment(buf);
		num = -temp;
	}
	buf_wrt(buf);
	append_num(buf, num);
	return (1);
}
/**
 * append_num - appends int to buffer
 * @buf: pointer to buffer
 * @num: number
 * Return: void
 */
void append_num(buffer *buf, unsigned int num)
{
	if (num == 0)
		return;
	buf_wrt(buf);
	append_num(buf, (num / 10));
	buf->str[buf->index] = (num % 10) + '0';
	buf_increment(buf);
}
/**
 * print_mod - prints modulus
 * @buf: pointer to buffer
 * @list: arguments
 * Return: int
 */
int print_mod(buffer *buf, va_list list)
{
	(void)list;

	buf_wrt(buf);
	buf->str[buf->index] = '%';
	buf_increment(buf);
	buf->str[buf->index] = '\0';
	return (1);
}


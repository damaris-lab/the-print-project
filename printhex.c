#include "main.h"

/**
 *printf_hex - prints  hexdecimal number
 * @val:no of arguements
 * Return:count
 */
int printf_hex(va_list val)
{
	int i;
	int *ptr;
	int count = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	ptr = malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		ptr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; 1 >= 0; i--)
	{
		if (ptr[i] > 9)
			ptr[i] = ptr[i] + 39;
		_putchar(ptr[i] + 'o');
	}
	free(ptr);
	return (count);
}

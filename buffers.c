#include "main.h"
/**
 * buf_size - gets the buffer size
 * @buf: poiter to the buffer
 * Return: size
 */
size_t buf_size(buffer *buf)
{
	if (!buf)
		return (0);
	return (buf->size);
}
/**
 * buf_copy - create a copy of the buffer
 * @buf: pointer to buffer
 * Return: pointer to copy
 */
char *buf_copy(buffer *buf)
{
	unsigned int i;
	char *copy;

	if (!buf)
		return (NULL);

	copy = malloc(sizeof(char) * buf->size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < buf->index)
	{
		copy[i] = buf->str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/**
 * write_buffer - writes buffer to str
 * @buf: pointer to buffer
 * Return: void
 */
void write_buffer(buffer *buf)
{
	if (!buf)
		return;
	write(1, buf->str, buf->index);
}
/**
 * buf_write - writes and reset the buffer
 * @buf: pointer to buffer
 * Return: void
 */
void buf_write(buffer *buf)
{
	if (!buf || (buf->index <= buf->size))
		return;
	write_buffer(buf);
	buf->index = 0;
	buf->str[0] = '\0';
}
/**
 * buf_increment - increments index and overflow
 * @buf: pointer to the buffer
 * Return: void
 */
void buf_increment(buffer *buf)
{
	if (!buf)
		return;
	buf->index++;
	buf->overflow++;
}

/**
 * new_buffer - creates a buffer
 * Return: pointer
 */
buffer *buf_new()
{
	buffer *buf;

	buf = malloc(sizeof(buffer));
	if (!buf)
		return (NULL);
	buf->index = 0;
	buf->size = 1024;
	buf->overflow = 0;
	buf->str = malloc(sizeof(char) * buf->size + 1);

	return (buf);
}
/**
 * custom_buffer - create a custom buffer
 * @size: size of buffer
 * Return: pointer to buffer
 */
buffer *custom_buffer(size_t size)
{
	buffer *buf;

	buf = malloc(sizeof(buffer));
	if (!buf)
		return (NULL);
	buf->index = 0;
	buf->size = size;
	buf->overflow = 0;
	buf->str = malloc(sizeof(char) * buf->size + 1);

	return (buf);
}
/**
 * end_buffer - frees the buffer
 * @buf: pointer to buffer
 * Return: void
 */
void end_buffer(buffer *buf)
{
	if (!buf)
		return;
	free(buf->str);
	free(buf);
}


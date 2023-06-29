#include "main.h"
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


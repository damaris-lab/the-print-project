#include "main.h"

/**
 * buf_increment - increments index and overflow
 * @buf: pointer to buffer
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
 * buf_new - create a default 1024 buffer
 * 
 * Return: pointer to buffer
 */
buffer *buf_new()
{
	buffer *buf;

	buf = malloc(sizeof(buffer));
	if(!buf)
		return (NULL);
	buf->index = 0;
	buf->size = 1024;
	buf->overflow = 0;
	buf->str = malloc(sizeof(char) * buf->size + 1);

	return (buf);
}
/**
 * buf_custom - create a custom buffer
 * @size: size of buffer
 * Return: pointer to buffer
 */
buffer *buf_custom(size_t size)
{
	buffer *buf;

	buf = malloc(sizeof(buffer));
	if (!buf)
		return (NULL);
	buf->index = 0;
	buf->overflow = 0;
	buf->size = size;
	buf->str = malloc(sizeof(char) * buf->size + 1);

	return (buf);
}
/**
 * buf_end - frees buffer memory
 * @buf: pointer to buffer
 * Return: void
 */
void buf_end(buffer *buf)
{
	if (!buf)
		return;
	free(buf->str);
	free(buf);
}
/**
 * buffer_size - get a buffer size
 * @buf: pointer to buffer
 * Return: size of buffer
 */
size_t buffer_size(buffer *buf)
{
	if (!buf)
		return (0);
	return (buf->size);
}
/**
 * buffer_index - get current index
 * @buf: pointer to buffer
 * Return: index
 */
size_t buffer_index(buffer *buf)
{
	if (!buf)
		return (0);
	return (buf->index);
}
/**
 * buffer_content - copy buffer contents
 * @buf: pointer to buffer
 * Return: pointer to copy
 */
char *buffer_content(buffer *buf)
{
	unsigned int i;
	char *temp;

	if (!buf)
		return (NULL);
	temp = malloc(sizeof(char) * buf->size + 1);
	if (!temp)
		return (NULL);
	i = 0;
	
	while (i < buf->index)
	{
		temp[i] = buf->str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
/**
 * buf_write - write the buffer
 * @buf: pointer to buffer
 * Return: void
 */
void buf_write(buffer *buf)
{
	if (!buf)
		return;
	write(1, buf->str, buf->index);
}
/**
 * buf_wrt - write and rest buffer
 * @buf: pointer to buffer
 * Return: void
 */
void buf_wrt(buffer *buf)
{
	if (!buf || (buf->index <= buf->size))
		return;
	buf_write(buf);
	buf->str[0] = '\0';
	buf->index = 0;
}


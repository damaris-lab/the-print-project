#ifndef MAIN_H

#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct type_s - structure to hold types
 * @var: variable
 * @f: matching function
 * Description: structure holds function calls
 */
typedef struct type_s
{
	char *identifier;
	int *function(buffer *, va_list);
}type_t;

type_t *type_t_init();

/**
 * struct print_buffer - struct for a print buffer
 * @index: index of buffer
 * @size: size of the buffer
 * @overflow: overflow
 * @str: pointer to memory buffer
 */
typedef struct print_buffer
{
	size_t index;
	size_t size;
	size_t overflow;
	char *str;
}buffer;
/*
 * buffer functions
 */
void buf_increment(buffer *buf);
buffer *buf_new();
buffer *buf_custom(size_t size);
void buf_end(buffer *buf);
void buf_wrt(buffer *buf);
void buf_write(buffer *buf);
char *buffer_content(buffer *buf);
size_t buffer_size(buffer *buf);
size_t buffer_index(buffer *buf);
/*
 * end buffer functions
 */
/*
 * start of print functions
 */
int _putchar(char c);
int operation(buffer *buf, va_list list, const char *src, int src_index);
int write_binary(buffer *buf, va_list list);
int print_mod(buffer *buf, va_list list);
void append_num(buffer *buf, unsigned int num);
int print_int(buffer *buf, va_list list);
int print_string(buffer *buf, va_list list);
int print_char(buffer *buf, va_list list);
int _printf(const char *format, ...);
/*
 * end print functions
 */

#endif/*MAIN_H*/


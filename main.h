#ifndef MAIN_H
#ifndef _GLOBAL_DEFINITIONS_H

#define _GLOBAL_DEFINITIONS_H
#define MAIN_H
#define NULL ((void *) 0)
#define True 1
#define False 0

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
	int (*function)(va_list);
} type_t;

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
} buffer;
/*
 * buffer functions
 */
buffer *buf_new();
buffer *custom_buffer(size_t);
void end_buffer(buffer *);
/*
 * end buffer functions
 */

/*
 * start of print functions
 */
int _print_mod(va_list list);
int _print_string(va_list list);
int _print_int(va_list list);
int _print_char(va_list list);
int _print_rev(va_list list);
int _print_rot13(va_list list);
int _printf(const char *format, ...);
int _putchar(char c);
/*
 * end print functions
 */

#endif/*global definations*/
#endif/*MAIN_H*/


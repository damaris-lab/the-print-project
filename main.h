#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
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
int _print_mod(va_list list);
int _print_string(va_list list);
int _print_int(va_list list);
int _print_char(va_list list);
int _print_rev(va_list list);
int _print_rot13(va_list list);

#endif/*MAIN_H*/


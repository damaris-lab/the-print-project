#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>

/**
 * struct var_type - structure for the variable types
 * @type: type of variable
 * @f: function to be called
 */
typedef struct var_type
{
	char type;
	void (*f)();
}var_type_t;

int _printf(const char *format, ...);

#endif/*MAIN_H*/


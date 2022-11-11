#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdarg.h>
#include <stdio.h>
typedef struct st
{
	char s;
	int (*f)(va_list a);
	} st_t;

int _printf(const char *format, ...);
int print_chare(va_list c);
int print_char(va_list c);
int veriformat(const char * const format);
#endif

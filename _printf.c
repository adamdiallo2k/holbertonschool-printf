#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "variadic_function.h"
#include <unistd.h>

/**
 * print_chare - Entry point
 * Description: 'return difference'
 * Return: nothing
 * @c: va_list parameter
 */
int print_chare(va_list c)
{
	int lenght = 0;
	int i = 0;
	char *r = va_arg(c, char *);

	if (r == NULL)
		r = "(nil)";

	while (r[i] != '\0')
	{
		lenght++;
		putchar(r[i]);
		i++;
	}
	return (lenght);
}

/**
 * print_char - Entry point
 * Description: 'return difference'
 * Return: nothing
 * @c: va_list parameter
 */
int print_char(va_list c)
{
	int r = va_arg(c, int);

	putchar(r);

	return (1);
}

/**
 * _printf - Entry point
 * Description: 'return division'
 * Return: nothing
 * @format: const parameter
 */

int _printf(const char * const format, ...)
{
	int lenght = 0;
	int i = 0, y = 0;
	st_t stu[] = {
		{"c", print_char},
		{"s", print_chare},
	};
	va_list parametersInfos;

	va_start(parametersInfos, format);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			y = 0;
			while (stu[y].s)
			{

				if (*stu[y].s ==  format[i + 1])
				{
					lenght = lenght + stu[y].f(parametersInfos);
					i++;
				}
				else if (format[i + 1] == '%')
				{
					putchar(format[i + 1]);
					lenght++;
					i++;
				}
				y++;
			}
		}
		else
		{
			putchar(format[i]);
			lenght++;
		}
		i++;
	}
	return (lenght);
}


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>

/**
 * print_chare - Entry point
 * Description: 'return difference'
 * Return: nothing
 * @c: va_list parameter
 */
int print_chare(va_list c)
{
	int count = 0;
	int i = 0;
	char *r = va_arg(c, char *);

	if (r == NULL)
		r = "(null)";

	while (r[i] != '\0')
	{
		count++;
		putchar(r[i]);
		i++;
	}
	return (count);
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

int veriformat(const char * const format)
{
	if (format == NULL)
		return (-1);
	return (0);
}

/**
 * _printf - Entry point
 * Description: 'return division'
 * Return: nothing
 * @format: const parameter
 */

int _printf(const char * const format, ...)
{
	int i = 0, y = 0, lenght = veriformat(format);
	st_t stu[] = {
		{"c", print_char},
		{"s", print_chare},
	};

	va_list parametersInfos;

	va_start(parametersInfos, format);

	while (format != NULL && format[i] != '\0')
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


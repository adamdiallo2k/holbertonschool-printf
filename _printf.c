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
	int y,i;
	int lenght = veriformat(format);
	st_t stu[] = {
		{"c", print_char},
		{"s", print_chare},
		{"0", NULL},
	};

	va_list parametersInfos;

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(parametersInfos, format);

	for (i = 0;format[i] != '\0'; i++)
	{	
		if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar(format[i]);
			lenght++;
			i++;
			continue;
		}	

		if (format[i] == '%') {
			for (y = 0; stu[y].s; y++)
			{
				if (*stu[y].s ==  format[i + 1])
				{
					lenght = lenght + stu[y].f(parametersInfos);
					i++;
					break;
				}	
			}

			if (*stu[y].s == '0')
			{
				putchar(format[i]);
				putchar(format[i + 1]);
				lenght +=2;
				i++;
				break;
			}
		}
		else  
		{
			putchar(format[i]);
			lenght++;
			i++;
		}
		
	}
	va_end(parametersInfos);
	return (lenght);
}


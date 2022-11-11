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
		write(1, &r[i], 1);
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

	return (write(1, &r, 1));

}


/**
 * _printf - Entry point
 * Description: 'return division'
 * Return: nothing
 * @format: const parameter
 */

int _printf(const char * const format, ...)
{
	int y, i, lenght = 0;
	va_list parametersInfos;
	st_t stu[] = {{'c', print_char}, {'s', print_chare}, {0, NULL}};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(parametersInfos, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			lenght += write(1, &format[i], 1);
			i++;
		}
		else if (format[i] == '%')
		{
			for (y = 0; stu[y].s != 0; y++)
			{
				if (format[i + 1] == stu[y].s)
				{
					lenght += stu[y].f(parametersInfos);
					i++;
					break;
				}
			}

			if (stu[y].s == 0)
			{
				lenght += write(1, &format[i], 1);
				lenght += write(1, &format[i + 1], 1);
				i++;
			}
		}
		else
			lenght += write(1, &format[i], 1);
	}
	va_end(parametersInfos);
	return (lenght);
}

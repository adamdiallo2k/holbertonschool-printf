#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

/**
* _putchar - Entry point
* Description: 'return difference'
* Return: int
* @c: char parameter
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_int - Entry point
 * Description: 'return difference'
 * Return: int
 * @c: va_list parameter
 */
int print_int(va_list c)
{
	int count;
	int r = va_arg(c, int);
	int i;

	if (r < 0)
		count += _putchar('-');
	for (i = 1000000000; i > 0; i /= 10)
	{
		if (r / i)
		{
			if ((r / i) % 10 < 0)
			{
				count += _putchar(-(r / i % 10) + '0');
			}
			else
			{
				count += _putchar((r / i % 10) + '0');
			}
		}
		else if (r / i == 0 && i == 1)
			count += _putchar(r / i % 10 + '0');
	}
	return (count);
}



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
	st_t stu[] = {{'c', print_char}, {'s', print_chare}, {'d', print_int}
		, {'i', print_int}, {0, NULL}};

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

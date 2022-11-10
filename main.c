#include <limits.h>
#include <stdio.h>
#include "variadic_function.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
  
    len = _printf("Let's %c %s try to printf a simple sentence.\n",'b',"azert");
    printf("%d",len);
    return (0);
}

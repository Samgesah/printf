#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
 * _printf - Printf function
 * @format: format.
 * Return: character string
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int numbers = 0;
	int (*f)(va_list);
	va_list directives;
	va_start(directives, format); 
	/*prevent passing a null pointer*/
	if (format == NULL )
		return (-1);
	while (format[i] != '\0')
		{
			if (format[i] != '%')
			{
				numbers = write(1, &format[i], 1);
				count = count + numbers;  
				i++;
				continue;
			}
			else
			{
				f = check_character_specification(&format[i + 1]);
				if (f != NULL)
				{
					numbers = f(directives);
					count += numbers;
					i++;
					continue;
				}
			
				
					
			}				
		}
	va_end(directives);
	return (count);
}

#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: character string
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int (*f)(va_list);
	va_list variables;
	va_start(variables, format); 
	/*prevent passing a null pointer*/
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && (format[1] == ' ' && !format[2]))
                return (-1);
	while (format[i] != '\0')
		{
			if (format[i] != '%')
			{
				count += write(1, &format[i], 1);  
				i++;
				continue;
			}
			else
			{
				i++;
				f = check_specificier(&format[i]);
				if (f != NULL)
				{
					count += f(variables);
					i++;
					continue;
				}
			
				
					
			}				
		}
	va_end(variables);
	return (count);
}

#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _printf - check specifier after %
 * @format: format.
 * Return: pointer to a function
 */
 int (*check_character_specification(const char *format))(va_list)
 {
	 int i;
	 func_t function_array[] = 
	 {
		 {"c", print_char},
		 {"s", print_str},
		 {"%", print_percent},
		 {NULL, NULL}
		 };
	for (i = 0; function_array[i].t != NULL; i++)
		{
			if (*(function_array[i].t) == *format)
			{
				return (function_array[i].f);
			}
			
		}
        return (NULL);
}

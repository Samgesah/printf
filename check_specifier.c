#include "main.h"
/**
 * check_specificier - check specifier after %
 * @fmt: char input
 * funct_specs[] - struct array to find whether next charcter is a specifier
 * Return: pointer to a function
 */
 int (*check_specificier(const char *fmt))(va_list)
 {
	 int i = 0;
	 func_t funct_specs[] = 
	 {
		 {"c", print_char},
		 {"s", print_string},
		 {"%", print_percent},
		 {"i", print_int},
		 {"d", print_int},
		 {NULL, NULL}
	 };
	for (i = 0; funct_specs[i].t != NULL; i++)
		{
			if (*(funct_specs[i].t) == *fmt)
			{
				return (funct_specs[i].s);
			}
			
		}
        return (NULL);
}

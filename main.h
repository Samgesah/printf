#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
int (*check_character_specification(const char *format))(va_list);
/**
*struct func - specifier struct
*@t: character to compare 
*f - handle printing 
*/
struct func
{
	char *t;
	int (*f)(va_list(directives));
} func_t;
int print_char(va_list directives);
int print_str (va_list directives);
int print_percent (va_list directives);
#endif

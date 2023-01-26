#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
int (*check_specificier(const char *fmt))(va_list);
/**
*struct func - specifier struct
*@t: character to compare
*f - handle printing
*/
typedef struct func
{
        char *t;
        int (*s)(va_list(variables));
} func_t;
int print_int(va_list variables);
int print_unsigned(va_list variables);
void print_number(int n);
int count_digit(int i);
int print_percent (va_list variables);
int print_string(va_list variables);
int print_char(va_list variables);
char *convert(unsigned long int num, int base, int lowercase);
int _putchar(char c);
int _puts(char *str);
#endif

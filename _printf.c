#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to turn on
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' char
 * @space: flag for the ' ' char
 * @hash: flag for the '#' char
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
*struct func - specifier struct
*@t: character to compare
*f - handle printing
*/
typedef struct func
{
        char t;
        int (*s)(va_list ap, flags_t *f);
} func_t;

/* print_nums */
int print_int(va_list variables, flags_t *f);
int print_unsigned(va_list variables, flags_t *f);
void print_number(int n);
int count_digit(int i);

/* print_bases */
int print_hex(va_list variables, flags_t *f);
int print_hex_big(va_list variables, flags_t *f);
int print_binary(va_list variables, flags_t *f);
int print_octal(va_list variables, flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* check_specifier */
 int (*check_specifier(char s))(va_list,  flags_t *);

/* check_flag */
int check_flag(char c, flags_t *f);

/* print_alpha */
int print_string(va_list variables, flags_t *f);
int print_char(va_list variables, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_bigS(va_list variables, flags_t *f);
int print_rev(va_list variables, flags_t *f);
int print_rot13(va_list variables, flags_t *f);

/* print_address */
int print_address(va_list variables, flags_t *f);

/* print_percent */
int print_percent(va_list variables,  flags_t *f);


#endif
/**
 * _printf - Printf function
 * @format: format.
 * Return: character string
 */
int _printf(const char *format, ...)
{
	flags_t flags = {0, 0, 0};
	int count = 0;
	int (*f)(va_list,  flags_t *);
	va_list variables;
	const char *L;
	va_start(variables, format);
	/*prevent passing a null pointer*/
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (L = format; *L; L++)
	{
		if (*L == '%')
		{
			L++;
			if (*L == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (check_flag(*L, &flags))
				L++;
			f = check_specifier(*L);
			count += (f)
				? f(variables, &flags)
				: _printf("%%%c", *L);
		} else
			count += _putchar(*L);
	}
	_putchar(-1);
	va_end(variables);
	return (count);
}

/**
 * check_specifier - check specifier after %
 *@s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * myarray[] - to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
 int (*check_specifier(char s))(va_list, flags_t *)
 {
	 int i;
	 func_t myarray[] = 
	 {
		 {'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};
		int vars = 14;
		for (i = 0; i < vars; i++)
		if (myarray[i].t == s)
		return (myarray[i].s);
	return (NULL);
}

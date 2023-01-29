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

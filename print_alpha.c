#include "main.h"
/**
 * print_string - loops through a string and prints
 * every character
 * @l: va_list arguments from _printf
 * Return: number of char printed
 */
int print_string(va_list variables, flags_t *f)
{
	char *s = va_arg(variables, char *);
	(void)f;
	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_char - prints a character
 * @l: va_list arguments from _printf
 * Return: number of char printed
 *
 *
 */ 
int print_char(va_list variables, flags_t *f)
{
	(void)f;
	_putchar(va_arg(variables, int));
	return (1);
}

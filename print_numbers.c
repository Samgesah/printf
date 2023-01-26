#include "main.h"
/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_int(va_list variables)
{
	int n = va_arg(variables, int);
	int res = count_digit(n);
	print_number(n);
	return (res);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list variables)
{
	unsigned int u = va_arg(variables, unsigned int);
	char *str = convert(u, 10, 0);
	return (_puts(str));
}

/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		print_number(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int k = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		k++;
	}
	return (k);
}

/**
 * print_percent - Printf a %  to stdout
 * @directives: variadic parameter
 * Return: number of characters printed
 */
int print_percent (va_list variables)
{
char c;
int count;
(void) variables;
 c = '%';
 count = 0;
 if (c)
 {
 count = write(1, &c, 1);
 return (count);
 }
 return (0);
}


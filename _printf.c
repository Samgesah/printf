#include "main.h"
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


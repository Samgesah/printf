#include 'main.h'
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
/**
 * print_int - prints an integer
 * @variables: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_int(va_list variables, flags_t *f)
{
	int n = va_arg(variables, int);
	int res = count_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	print_number(n);
	return (res);
}

/**
 * print_unsigned - prints an unsigned integer
 * @variables: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list variables, flags_t *f)
{
	unsigned int u = va_arg(variables, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}

/**
 * print_percent - prints a percent
 * @variables: va_list arguments from _printf
 * Return: number of char printed
 */
int print_percent(va_list variables,  flags_t *f)
{
	(void)f;
	(void)variables;
	return (_putchar('%'));
}
**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 * Description: _putchar uses a local buffer of 1024 to call write
 * as little as possible
 */

int _putchar(char c)
  
{
  
  static char buf[1024];
  
  static int i;
  

  
  if (c == -1 || i >= 1024)
    
    {
      
      write(1, &buf, i);
      
      i = 0;
      
    }
  
  if (c != -1)
    
    {
      
      buf[i] = c;
      
      i++;
      
    }
  
  return (1);
  
}


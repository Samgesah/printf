#include "main.h"
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

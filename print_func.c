#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_char - Printf a character to stdout
 * @directives: variadic parameter
 * Return: number of characters printed 
 */
int count = 0;
int  print_char(va_list directives)
{
   char c = (char)va_arg(directives, int);
   int count = 0;
   if (c)
   {
	   count = write(1, &c, 1);
	   return (count);
   }
	return (0);
	
}
/**
 * print_str - Printf a string char by char to stdout
 * @directives: variadic parameter
 * Return: number of characters printed 
 */
int print_str (va_list directives)
{
 int i;
 char *s = va_arg(directives, char*);
 if (s)
 {
 for (i =0; s[i] != '\0'; i++)
 {
	 write(1, &s, 1);
	 i++;
 }
 }
	return (0);
}
/**
 * print_percent - Printf a %  to stdout
 * @directives: variadic parameter
 * Return: number of characters printed 
 */
int print_percent (va_list directives)
{
	char c = '%';
	if (c)
   {
	   count = write(1, &c, 1);
	   return (count);
   }
	return (0);
}

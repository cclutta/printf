#include "main.h"

/**
* printf - like printf
* @format - const chhar pointer
* 
* Return: num
*/

int _printf(const char *format, ...)
{
	va_list arg;
	const char *s;
	int c = 0;
	
	if (!format)
		return (-1);
	
	va_start(arg, format);
	s = format;
	
	c = get_format(arg, s);
	va_end(arg);
	return (c);
	
}

int get_format(va_list arg, const char *string)
{
	
}

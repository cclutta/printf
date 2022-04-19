#include "main.h"

/**
 * function_manager - function manager
 * @c: char
 * @arg: va_list 
 *
 * Return: int
 */
int function_manager(char c, va_list arg)
{
	int c1 = 0;

	c1 = _switch(c, arg);
	if (c == 'p')
		c1 = print_ptr(arg);
	return (c1);
}
/**
* _switch - switch function
* @c: char
* @arg: va_list
*
* Return: int
*/
int _switch(char c, va_list arg)
{
	int c1 = 0;

	switch (c)
	{
		case 'd':
		case 'i':
			c1 += print_sign(arg, 10);
			break;
		case 'b':
			c1 += print_unsign(arg, 2);
			break;
		case 'c':
			c1 += print_character(arg);
			break;
		case 'o':
			c1 += print_unsign(arg, 8);
			break;
		case 'r':
			c1 += print_rev(arg);
			break;
		case 'R':
			c1 += print_rot13(arg);
			break;
		case 's':
			c1 += print_string(arg);
			break;
		case 'u':
			c1 += print_unsign(arg, 10);
			break;
		case 'x':
			c1 += print_base16_upper_lower(arg, "0123456789abcdef");
			break;
		case 'X':
			c1 += print_base16_upper_lower(arg, "0123456789ABCDEF");
			break;
		default:
			c1 = -1;
	}
	return (c1);
}

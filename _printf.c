#include "main.h"

/**
* _printf - like printf
* @format: const chhar pointer
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
/**
* get_format - get the format
* @arg: arg
* @string: const char pointer
*
* Return: num
*/

int get_format(va_list arg, const char *string)
{
	int i = 0, c = 0, c_fm = 0, percent = 0, f = 0;
	while (i < _strlen((char *)string) && *string != '\0')
	{
		char a = string[i];
		if (a == '%')
		{
			i++, f++;
			a = string[i];
			if (a == '\0' && _strlen((char *)string) == 1)
			{
				return (-1);
			}
			if (a == '\0')
			{
				return (c);
			}
			if (a == '%')
			{
				f++;
			}
			else
			{
				c_fm = _function_manager(a, arg);
				if (c_fm >= 0 && c_fm != -1)
				{
					i++;
					a = string[i];
					if (a == '%')
						f--;
					c = c + c_fm;
				} else if (c_fm == -1 && a != '\n')
				{
					c += _putchar('%');
				}
			}
		}
		percent = check_percent(&f, a);
		c += percent;
		if (percent == 0 && a != '\0' && a != '%')
			c += _putchar(a), i++;
		percent = 0;
	}
	return (c);
}

/**
 * check_percent - check percent
 * @f: int
 * @a: character
 *
 * Return: num
 */
int check_percent(int *f, char a)
{
	int tmp;
	int c = 0;

	tmp = *f;
	if (tmp == 2 && a == '%')
	{
		_putchar('%');
		tmp = 0;
		c = 1;
	}
	return (c);
}

/**
 * _function_manager - function manager
 * @a: character parameter
 * @arg: va_list arg
 *
 * Return: num
 */

int _function_manager(char a, va_list arg)
{
	int c = 0;

	c = function_manager(a, arg);
	return (c);
}


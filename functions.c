#include "main.h"

/**
 * _putchar - writes c
 * @c: char
 *
 * Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _strlen - get length
* @s: char pointer
*
* Return: int
*/
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
	{
		len++;
	}
	return (len);
}

/**
 * _puts - print string
 * @str: char pointer
 *
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; i < _strlen(str); i++)
	{
		_putchar(str[i]);
	}
}

/**
* convert_to - convert
* @representation: char array
* @num: int
* @base: int
*
* Return: char
*/
char *convert_to(char representation[], unsigned int num, int base)
{
	char *ptr;
	static char buffer[128];
	int mod = 0;

	ptr = &buffer[127];
	*ptr = '\0';

	do {
		mod = num % base;
		*--ptr = representation[mod];
		num /= base;
	} while (num != 0);
	return (ptr);
}

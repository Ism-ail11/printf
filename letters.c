#include "main.h"

/**
 * _print_char - prints a character to the screen
 * @valist: variable list of arguments
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 *
 * Return: void
 */
int _print_char(va_list valist, flag_t *f, mod_t *m)
{
	char ch = (char)va_arg(valist, int);
	int spaces, i;

	(void)f;

	if (m->width > 0)
	{
		spaces = m->width - 1;
		for (i = 0; i < spaces; i++)
			_putchar(' ');
	}

	_putchar(ch);

	return (1);
}

/**
 * _print_str - prints a string to the screen
 * @valist: variable list of arguments
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 *
 * Return: number of character
 */
int _print_str(va_list valist, flag_t *f, mod_t *m)
{
	char *str = va_arg(valist, char *);
	int i, spaces, count = 0;

	(void)f;

	if (!str)
		str = "(null)";
	while (str[count] != '\0')
		count++;
	if (m->width > count)
	{
		spaces = m->width - count;
		for (i = 0; i < spaces; i++)
			_putchar(' ');
	}
	_puts(str);
	return (count);
}


#include "main.h"

/**
 * _print_address - prints addresses
 * @valist: variable arguments
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 *
 * Return: count
 */
int _print_address(va_list valist, flag_t *f, mod_t *m)
{
	char *str;
	int count = 0;
	unsigned long int addr = va_arg(valist, unsigned long int);
	int spaces, i;

	if (!addr)
	{
		return (_puts("(nil)"));
	}

	(void)f;

	str = convert(addr, 16, 1);
	while (str[count] != '\0')
		count++;
	if (m->width > count)
	{
		spaces = m->width - count;
		for (i = 0; i < spaces; i++)
			_putchar(' ');
	}
	count += _putchar('0');
	count += _putchar('x');

	_puts(str);

	return (count);
}

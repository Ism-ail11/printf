#include "main.h"

/**
 * _print_binary - function to print base two numbers
 * @valist: valist parameter
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 * Return: length
 */
int _print_binary(va_list valist, flag_t *f, mod_t *m)
{
	unsigned int num = va_arg(valist, unsigned int);
	char *str;
	int spaces, i, count = 0;

	(void)f;

	str = convert(num, 2, 1);
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

/**
 * _print_hexa_upper - prints numbers in uppercase hexadecimal format
 * @valist: va_list parameter
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 *
 * Return: length of number
 */
int _print_hexa_upper(va_list valist, flag_t *f, mod_t *m)
{
	unsigned long lnum = va_arg(valist, unsigned long);
	unsigned int num = 0;
	unsigned short snum = 0;
	char *str;
	int spaces, i, count = 0;

	if (m->l == 0 && m->h == 1)
	{
		snum = (unsigned short)lnum;
		lnum = snum;
	}
	if (m->l == 0 && m->h == 0)
	{
		num = (unsigned int)lnum;
		lnum = num;
	}

	str = convert(lnum, 16, 0);
	while (str[count] != '\0')
		count++;
	if (m->width > count)
	{
		spaces = m->width - count;
		for (i = 0; i < spaces; i++)
			_putchar(' ');
	}
	if (f->hash == 1 && str[0] != '0')
		count += _puts("0X");
	_puts(str);
	return (count);
}

/**
 * _print_hexa_lower - prints numbers in lowercase hexadecimal format
 * @valist: va_list parameter
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 *
 * Return: length of number
 */
int _print_hexa_lower(va_list valist, flag_t *f, mod_t *m)
{
	unsigned long lnum = va_arg(valist, unsigned long);
	unsigned int num = 0;
	unsigned short snum = 0;
	char *str;
	int spaces, i, count = 0;

	if (m->l == 0 && m->h == 1)
	{
		snum = (unsigned short)lnum;
		lnum = snum;
	}
	if (m->l == 0 && m->h == 0)
	{
		num = (unsigned int)lnum;
		lnum = num;
	}
	str = convert(lnum, 16, 1);
	while (str[count] != '\0')
		count++;
	if (m->width > count)
	{
		spaces = m->width - count;
		for (i = 0; i < spaces; i++)
			_putchar(' ');
	}
	if (f->hash == 1 && str[0] != '0')
		count += _puts("0x");
	_puts(str);
	return (count);
}

/**
 * _print_octal - prints numbers in octal format
 * @valist: va_list parameter
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 *
 * Return: length of number
 */
int _print_octal(va_list valist, flag_t *f, mod_t *m)
{
	unsigned long lnum = va_arg(valist, unsigned long);
	unsigned int num = 0;
	unsigned short snum = 0;
	char *str;
	int spaces, i, count = 0;

	if (m->l == 0 && m->h == 1)
	{
		snum = (unsigned short)lnum;
		lnum = snum;
	}
	if (m->l == 0 && m->h == 0)
	{
		num = (unsigned int)lnum;
		lnum = num;
	}
	str = convert(lnum, 8, 1);
	while (str[count] != '\0')
		count++;
	if (m->width > count)
	{
		spaces = m->width - count;
		for (i = 0; i < spaces; i++)
			_putchar(' ');
	}
	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');
	_puts(str);
	return (count);
}

/**
 * _print_unsigned - prints unsigned numbers
 * @valist: valist parameter
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 *
 * Return: str array
 */
int _print_unsigned(va_list valist, flag_t *f, mod_t *m)
{
	unsigned long lnum = va_arg(valist, unsigned long);
	unsigned int num = 0;
	unsigned short snum = 0;
	char *str;
	int spaces, i, count = 0;

	if (m->l == 0 && m->h == 1)
	{
		snum = (unsigned short)lnum;
		lnum = snum;
	}
	if (m->l == 0 && m->h == 0)
	{
		num = (unsigned int)lnum;
		lnum = num;
	}

	(void)f;
	str = convert(lnum, 10, 1);
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

#include "main.h"

/**
 * _print_dec - prints decimal numbers
 * @valist: variable list of arguments
 * @f: pointer to flag_t
 * @m: pointer to mod_t
 * Return: Always (0);
 */
int _print_dec(va_list valist, flag_t *f, mod_t *m)
{
	long lnum = va_arg(valist, long);
	int count, num = 0;
	short snum = 0;
	int spaces, i;

	if (m->l == 0 && m->h == 1)
	{
		snum = (short) lnum;
		lnum = snum;
	}
	if (m->l == 0 && m->h == 0)
	{
		num = (int) lnum;
		lnum = num;
	}
	count = count_digits(lnum);
	if (m->width > count)
	{
		spaces = m->width - count;
		for (i = 0; i < spaces; i++)
			_putchar(' ');
	}
	if (f->space == 1 && f->plus == 0 && lnum >= 0)
		count += _putchar(' ');
	if (f->plus == 1 && lnum >= 0)
		count += _putchar('+');
	if (lnum <= 0)
		count++;
	print_number(lnum);
	return (count);
}


/**
 * print_number - helps other functions print numbers to stdout
 * @n: int parameter
 *
 * Return: void
 */
void print_number(long n)
{

	unsigned long m;

	if (n < 0)
	{
		_putchar('-');
		m = -n;
	}
	else
	{
		m = n;
	}

	if (m / 10)
		print_number(m / 10);
	_putchar('0' + (m % 10));
}


/**
 * count_digits - counts the number of digits in a number
 * @n: int parameter
 *
 * Return: number of digits
 */
int count_digits(long n)
{
	unsigned int count = 0;
	unsigned long m;

	if (n < 0)
		m = (-1 * n);
	else
		m = n;
	while (m != 0)
	{
		m /= 10;
		count++;
	}
	return (count);
}



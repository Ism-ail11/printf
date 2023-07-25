#include "main.h"

/**
 * _printf - main printf function
 * @format: string parameter
 *
 * Return: count of characters in @format
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *str;
	int (*func)(va_list, flag_t *, mod_t *);
	flag_t f = {0, 0, 0};
	mod_t m = {0, 0, 0};
	int i, count = 0, num = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (str = format; *str; str++)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
			{
				count += _putchar('%');
				continue;
			}
			for (; get_flags(*str, &f); str++)
			{}
			for (i = 0; *str >= 48 && *str <= 57; str++, i++)
				num = (num * (i * 10)) + (*str - '0');
			set_width(num, &m);
			for (; get_modifier(*str, &m); str++)
			{}
			func = get_func(*str);
			count += (func) ? func(args, &f, &m)
					: _printf("%%%c", *str);
		} else
			count += _putchar(*str);
	}
	_putchar(-1), va_end(args);
	return (count);
}


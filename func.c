#include "main.h"

/**
 * get_func - returns the function to use based on an inputted char
 * @c: char parameter
 *
 * Return: pointer to function
 */
int (*get_func(char c))(va_list, flag_t *, mod_t *)
{
	id char_ids[] = {
		{'d', _print_dec},
		{'i', _print_dec},
		{'s', _print_str},
		{'c', _print_char},
		{'b', _print_binary},
		{'x', _print_hexa_lower},
		{'X', _print_hexa_upper},
		{'o', _print_octal},
		{'u', _print_unsigned},
		{'S', _print_specifier},
		{'p', _print_address},
		{'%', _print_percent},
		{'r', _print_reverse},
		{'R', _print_rot13}
	};
	int i;
	int flags = 14;


	for (i = 0; i < flags; i++)
		if (char_ids[i].symbol == c)
			return (char_ids[i].func);

	return (NULL);
}

#include "main.h"

/**
 * convert - converts a decimal number into any other base
 * @num: unsigned int parameter
 * @base: int parameter
 * @lowercase: int parameter
 * Return: pointer to the string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char buffer[40];
	static char *ptr;
	char *map;

	map = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[39];
	*ptr = '\0';

	do {
		ptr--;
		*ptr = map[num % base];
		num = num / base;
	} while (num != 0);

	return (ptr);
}

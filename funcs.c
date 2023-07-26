#include "main.h"

/**
 * _putchar - prints a character at a time to the screen
 * @c: char parameter
 *
 * Return: On success give 1 On error print -1
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buffer, i);
		i = 0;
	}
	if (c != -1)
	{
		buffer[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - Helps print a string to the terminal
 * @str: string parameter
 *
 * Return: number of characters in @str
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}

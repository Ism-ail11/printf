#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct flags - struct for flags
 * struct modifiers - struct for modifiers
 * struct identifiers - struct for identifiers
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flag_t;

typedef struct modifiers
{
	int l;
	int h;
	int width;
} mod_t;

typedef struct identifiers
{
	char symbol;
	int (*func)(va_list, flag_t *, mod_t *);
} id;

int _printf(const char *format, ...);

int _putchar(char c);
int _puts(char *str);

int _print_char(va_list, flag_t *, mod_t *);
int _print_str(va_list, flag_t *, mod_t *);
int _print_specifier(va_list, flag_t *, mod_t *);

int  _print_dec(va_list, flag_t *, mod_t *);

void print_number(long n);
int count_digits(long n);
char *convert(unsigned long num, int base, int lowercase);

int _print_binary(va_list, flag_t *, mod_t *);
int _print_hexa_upper(va_list, flag_t *, mod_t *);
int _print_hexa_lower(va_list, flag_t *, mod_t *);
int _print_octal(va_list, flag_t *, mod_t *);
int _print_unsigned(va_list, flag_t *, mod_t *);
int _print_address(va_list, flag_t *, mod_t *);
int _print_percent(va_list, flag_t *, mod_t *);
int _print_reverse(va_list, flag_t *, mod_t *);
int _print_rot13(va_list, flag_t *, mod_t *);

/* Generate function pointer */
int (*get_func(char c))(va_list, flag_t *, mod_t *);

/* Set flags */
int get_flags(char elem, flag_t *);

/* Set modifiers */
int get_modifier(char elem, mod_t *);
void set_width(int width, mod_t *);

#endif

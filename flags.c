#include "main.h"

/**
 * get_flags - determines which flags to set based on the format strings
 * @elem: char parameter
 * @f: flag_t parameter
 *
 * Return: return code
 */
int get_flags(char elem, flag_t *f)
{
	int i = 0;

	switch (elem)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}
	return (i);
}

#include "main.h"

/**
 * get_modifier - sets the length modifier based on characters found
 * @elem: char parameter
 * @m: pointer to mod_t struct
 *
 * Return: 1 or 0 (Depending on whether the character is found)
 */
int get_modifier(char elem, mod_t *m)
{
	int i = 0;

	switch (elem)
	{
		case 'l':
			m->l = 1;
			i = 1;
			break;
		case 'h':
			m->h = 1;
			i = 1;
			break;
	}
	return (i);
}

/**
 * set_width - sets the width attribute of the mod_t struct
 * @width: int parameter
 * @m: pointer to mod_t struct
 *
 * Return: void
 */
void set_width(int width, mod_t *m)
{
	if (width >= 0)
		m->width = width;
}

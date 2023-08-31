#include "main.h"

/**
 * get_endianness - checks if machine is little or big endian
 * Return: 0 big, 1 small
 */

int get_endianness(void)
{
	unsigned int r = 1;
	char *c = (char *) &r;

	return (*c);
}


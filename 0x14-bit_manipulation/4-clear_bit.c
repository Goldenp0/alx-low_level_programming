#include "main.h"

/**
 * clear_bit - sets value of given bit to 0
 * @n: pointer digit to change
 * @index: index of the bit to clear
 *
 * Return: 1 (success), -1 if fail
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

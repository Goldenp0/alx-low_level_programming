#include "main.h"

/**
 * flip_bits - counts digit of bits to the change
 * get from one number to another
 * @n: first digit
 * @m: second digit
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int r, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (r = 63; r >= 0; r--)
	{
		current = exclusive >> r;
		if (current & 1)
			count++;
	}

	return (count);
}

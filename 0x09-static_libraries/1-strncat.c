#include "main.h"
/**
  * _strncat - function concatenate teo strings
  * using at most n bytes from src
  * @dest: entered value
  * @src: entered value
  * @n: entered value
  *
  * Return: dest
  */

char *_strncat(char *dest, char *src, int n)
{
	int c;
	int d;

	c = 0;
	while (dest[c] != '\0')
	{
		c++;
	}
	d = 0;
	while (d < n && src[d] != '\0')
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = '\0';
		return (dest);
}

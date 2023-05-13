#include "main.h"
/**
  * _memcpy -a function that copies memory area
  * @dest: memory where is stored
  * @src: memory where is copied
  * @n: number of bytes
  *
  * Return: copies memory with n bytes changed
  */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int l = 0;
	int p = n;

	for (; l < p; l++)
	{
		dest[l] = src[l];
		n--;
	}
	return (dest);
}


#include "main.h"
/**
  * char *_strcpy - print copies of the string pointed to by src
  * @dest: copy to
  * @src: copy from
  * Return: string value
  */

char *_strcpy(char *dest, char *src)
{
	int c = 0;
	int f = 0;

	while (*(src + c) != '\0')
	{
		c++;
	}
	for (; f < c ; f++)
	{
		dest[f] = src[f];
	}
	dest[c] = '\0';
	return (dest);
}

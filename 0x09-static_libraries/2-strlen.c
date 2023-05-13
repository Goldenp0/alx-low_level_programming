#include "main.h"
/**
  * _strlen - return the length of a string
  * @s: string
  * Return: length
  */

int _strlen(char *s)
{
	int longie = 0;

	while (*s != '\0')
	{
		longie++;
		s++;
	}
	return (longie);
}

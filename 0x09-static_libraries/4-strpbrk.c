#include "main.h"
/**
  * _strpbrk - print entry point
  * @s: input
  * @accept: input
  * Return: Always 0 (success)
  */

char *_strpbrk(char *s, char *accept)
{
	int f;

	while (*s)
	{
		for (f = 0; accept[f]; f++)
		{
			if (*s == accept[f])
				return (s);
		}
		s++;
	}
	return ('\0');
}

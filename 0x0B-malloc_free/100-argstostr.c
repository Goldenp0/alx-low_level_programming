#include "main.h"
#include <stdlib.h>
/**
  * argstostr - main entry
  * @ac: int input
  * @av: double pointer array
  * Return: 0
  */

char *argstostr(int ac, char **av)
{
	int i, n, x = 0, y = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
			y++;
	}
	y += ac;

	str = malloc(sizeof(char) * y + 1);
		if (str == NULL)
			return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
		{
			str[x] = av[i][n];
			x++;
		}
		if (str[x] == '\0')
		{
			str[x++] = '\n';
		}
	}
	return (str);
}

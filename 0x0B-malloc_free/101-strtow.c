#include "main.h"
#include <stdlib.h>
/**
  * count_word - write helper function to count the number of words in a string
  * @s: string to evalute
  *
  * Return: number of words
  */

int count_word(char *s)
{
	int flag, r, q;

	flag = 0;
	q = 0;

	for (r = 0; s[r] != '\0'; r++)
	{
		if (s[r] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			q++;
		}
	}

	return (q);
}
/**
  * **strtow - splits a string int words
  * @str: string to split
  *
  * Return: pointer toan array of atrings (success)
  * or NULL (error)
  */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int l, n = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (l = 0; l <= len; l++)
	{
		if (str[l] == ' ' || str[l] == '\0')
		{
			if (c)
			{
				end = l;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[n] = tmp - c;
				n++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = l;
	}

	matrix[n] = NULL;

	return (matrix);
}

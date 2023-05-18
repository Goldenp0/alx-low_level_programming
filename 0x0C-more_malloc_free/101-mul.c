#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
  * is_digit - checks if a string contains a non-digit char
  * @s: string to be evaluted
  *
  * Return: 0 if a non-digit is found, 1 otherwise
  */

int is_digit(char *s)
{
	int r = 0;

	while (s[r])
	{
		if (s[r] < '0' || s[r] > '9')
			return (0);
		r++;
	}
	return (1);
}
/**
  * _strlen - returns the length of a string
  * @s: string to evalute
  *
  * Return: the length of the string
  */

int _strlen(char *s)
{
	int r = 0;

	while (s[r] != '\0')
	{
		r++;
	}
	return (r);
}

/**
  * errors - handles errors for main
  */

void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
  * main - multiplies two positive numbers
  * @argc: number of arguments
  * @argv: array of arguments
  *
  * Return: always 0 (success)
  */

int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, r, carry, digit1, digit2, *result, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		errors();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (r = 0; r <= len1 + len2; r++)
		result[r] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			digit2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len1 + 1] += carry;
	}
	for (r = 0; r < len - 1; r++)
	{
		if (result[r])
			a = 1;
		if (a)
			_putchar(result[r] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}

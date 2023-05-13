#include <stdio.h>
#include "main.h"

/**
  * main - progran prints all argument it will receive
  * @argc: number of arguments
  * @argv: array of arguments
  *
  * Return: Alwayss 0 (success)
  */

int main(int argc, char *argv[])
{
	int n;

	for (n = 0; n < argc; n++)
	{
		printf("%s\n", argv[n]);
	}

	return (0);
}

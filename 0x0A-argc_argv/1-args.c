#include <stdio.h>
#include "main.h"

/**
  * main - program print the number of arguments passed to the program
  * @argc: number of arguments
  * @argv: array of arguments
  *
  * Return: Always 0 (success)
  */

int main(int argc, char *argv[])
{
	(void) argv; /*Ignore argv*/
		printf("%d\n", argc - 1);

	return (0);
}

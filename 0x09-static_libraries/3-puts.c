#include "main.h"
/**
  * _puts - prints a string to stdout
  * @s: the string to be printed
  * _putchar prints a new line
  */

void _puts(char *s)
{
	while (*s)
		_putchar(*s++);

	_putchar('\n');
}

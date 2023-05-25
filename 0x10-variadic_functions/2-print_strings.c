#include "variadic_function.h"
#include <stdio.h>
#include <stdarg.h>

/**
  * print_strings - Prints strings, followed by a new line of the progaram
  * @separator: The string to be printed between strings.
  * @n: The number of strings passed to the function.
  * @...:A variable number of strings to be printed.
  *
  * *Description: if separator is NULL, it won't be printed.
  *         If one of the strings if NULL, (nil) is printed instead.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list string;
	char *str;
	unsigned int index;

	va_start(strings, n);

	for (index = 0; index < n; index++)
	{
		str = va_arg(strings, char*);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (index != (n - 1) && separatot != NULL)
			printf("%s", separator);
	}

	print("\n");

	va_end(strings);
}

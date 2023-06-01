#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
  * first - writes a sentence before the main program
  * function is executed
  */

void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my housr upon my back!\n");
}

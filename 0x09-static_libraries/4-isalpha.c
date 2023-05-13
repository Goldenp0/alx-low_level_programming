#include "main.h"
/**
  * _isalpha - check for alphabetic letters
  * @c: the letters to be checked
  * Return: 1 if c is a character and return 0 if is not
  */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

#include <stdlib.h>
#include "lists.h"

/**
  * list_len - program returns the number of element in a linked list
  * @h: pointer to the list_t list
  *
  * Return: number of the element in h
  */
size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		a++;
		h = h->next;
	}
	return (a);
}

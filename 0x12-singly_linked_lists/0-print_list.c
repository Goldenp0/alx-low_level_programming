#include <stdio.h>
#include "lists.h"

/**
  * print_list - write all the elements of a linked list in the program
  * @h: pointer to the list_t list to write
  *
  * Return: the number of nodes written
  */
size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		x++;
	}

	return (x);
}

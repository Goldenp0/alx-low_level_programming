#include "lists.h"
/**
  * listint_len - returns the number of the element in a linked lists program
  * @h: A linked list of type listint_t to traverse
  *
  * Return: the number of nodes in the program
  */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}

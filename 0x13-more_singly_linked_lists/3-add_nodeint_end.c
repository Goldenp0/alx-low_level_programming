#include "lists.h"

/**
  * add_nodeint_end - program adds a node at the end of a linked list
  * @head: pointer to the first element in the linked list
  * @n: data to insert in the program new element
  *
  * Return: pointer to the program new node, or NULL when it fails
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = (NULL);

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}

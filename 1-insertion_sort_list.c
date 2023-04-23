#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: A double linked list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current,
		  *previous,
		  *tmp;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
	       return;	

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		previous = current->prev;

		while (previous != NULL && current->n < previous->n)
		{
			nswap(list, &previous, current);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * nswap - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node.
 * @node2: The second node
 * Return : Nothing
 */

void nswap(listint_t **head, listint_t **node1, listint_t *node2)
{
	if ((*head) == NULL || (*node1) == NULL || node2 == NULL)
		return;
	/* update the next and prev node for the second node */
	(*node1)->next = node2->next;

	/*(*node1)->prev = node2->prev;*/
	 /* node2->next = *node1;*/

	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;

	/* update the current node pointer */

	(*node1)->prev = node2;
	*node1 = node2->prev;
}



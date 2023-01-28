#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints
 *
 * Description: uses 'insertion sort' algorithm to sort the list
 * in ascending order.
 *
 * @list: doubly linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head;
	listint_t *node;
	listint_t *prev;

	if (!list || (*list)->next == NULL)
	{
		return;
	}

	head = *list;
	node = head->next;
	while (node)
	{
		prev = node->prev;
		if (node->n < prev->n)
		{
			find_position(list, node);
		}
		node = node->next;
	}
}

/**
 * find_position - inserts a node into ordered position in list.
 *
 * @list: double linked list.
 * @node: list item (holds an integer value)
 */
void find_position(listint_t **list, listint_t *node)
{
	listint_t *prev;
	prev = node->prev;

	if (!node || prev == NULL)
	{
		return;
	}

	if (node->n < prev->n)
	{
		swap_nodes(list, prev, node);
		print_list(*list);
		find_position(list, node);
	}
}

/**
 * swap_nodes - interchange the position of 2 nodes in a list.
 *
 * @list: double linked list
 * @n1: first node (on the left of n2)
 * @n2: second node (on the right of n1)
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	/* nodes preceding and succeeding the n1-n2 pair */
	listint_t *prec;
	listint_t *succ;

	prec = n1->prev;
	succ = n2->next;

	if (prec)
	{
		prec->next = n2;
	}
	if (succ)
	{
		succ->prev = n1;
	}

	n1->prev = n2;
	n1->next = succ;

	n2->prev = prec;
	n2->next = n1;
	if (n1 == *list)
	{
		*list = n2;
	}
}

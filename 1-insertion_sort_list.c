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
	listint_t *temp;
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
			temp = node;
			node = node->next;
			find_position(list, temp);
			continue;
		}
		node = node->next;
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
	listint_t *temp;

	temp = n2->next;

	n2->prev = n1->prev;
	n2->next = n1;
	if (n1 == *list)
	{
		*list = n2;
	}

	n1->prev = n2;
	n1->next = temp;
}

/**
 * find_position - inserts a node into ordered position in list.
 *
 * @list: double linked list.
 * @node: list item (holds an integer value)
 */
void find_position(listint_t **list, listint_t *node)
{
	listint_t *temp;
	listint_t *prev;

	if (!node || node->prev == NULL)
	{
		return;
	}

	prev = node->prev
	if (node->n < prev->n)
	{
		temp = node;
		swap_nodes(list, prev, node);
		print_list(*list);
		find_position(list, temp);
	}
}

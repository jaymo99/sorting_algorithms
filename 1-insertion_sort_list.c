#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list on ints
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
	listint_t *pos;

	if (!list)
	{
		return;
	}

	head = *list;
	node = head;
	while (node->next)
	{
		temp = node->next;
		if (node->n > temp->n)
		{
			remove_node(temp);
			pos = find_position(temp->n, node);
			head = insert_node(list, temp, pos);

			if (head != *list)
			{
				*list = head;
			}
			print_list(*list);
		}
		else
		{
			node = node->next;
		}
	}
}

/**
 * find_position - finds ordered list position to insert a node.
 *
 * @val: integer value
 * @succ: successor node
 *
 * Return: returns the successor node of the identified position.
 */
listint_t *find_position(int val, listint_t *succ)
{
	listint_t *prev = succ->prev;

	if (prev == NULL || prev->n <= val)
	{
		return (succ);
	}
	return (find_position(val, prev));
}

/**
 * remove_node - removes node/item from doubly linked list
 *
 * Description: Can remove any node except the head/first node
 *
 * NOTE: the node is only removed but not deleted
 *
 * @node: node/list-item to be removed
 */
void remove_node(listint_t *node)
{
	listint_t *prev = node->prev;
	listint_t *next = node->next;

	node->prev = NULL;
	node->next = NULL;

	if (prev)
	{
		prev->next = next;
	}
	if (next)
	{
		next->prev = prev;
	}
}

/**
 * insert_node - inserts node at a position in double linked list.
 *
 * @list: doubly linked list of integers.
 * @node: node to be inserted
 * @succ: node succeeding the inserted node
 *
 * Return: head/first-node of the doubly linked list.
 */
listint_t *insert_node(listint_t **list, listint_t *node, listint_t *succ)
{
	listint_t *prev = succ->prev;

	if (prev)
	{
		prev->next = node;
	}
	node->prev = prev;
	node->next = succ;
	succ->prev = node;

	if (node->prev == NULL)
	{
		return (node);
	}

	return (*list);
}

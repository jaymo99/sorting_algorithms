#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* DATA STRUCTURES */
/* --------------- */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/**
 * struct p_array - printable array
 *
 * Description: used to keep track of the initial/original
 * unpartitioned array that can be printed in full.
 *
 * @array: array of integers
 * @size: size of the array
 */
typedef struct p_array
{
	const int *array;
	size_t size;
} p_array;



/* FUNCTION PROTOTYPES */
/* -------------------- */

/* File - print_array.c */
void print_array(const int *array, size_t size);

/* File - print_list.c */
void print_list(const listint_t *list);

/* File - 0-bubble_sort.c */
void bubble_sort(int *array, size_t size);

/* File - 1-insertion_sort_list.c */
void insertion_sort_list(listint_t **list);
void find_position(listint_t **list, listint_t *node);
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2);

/* File - 2-selection_sort.c */
void selection_sort(int *array, size_t size);

/* File - 3-quick_sort.c */
void quick_sort(int *array, size_t size);
void q_sort(p_array printable, int *array, size_t size);
int partition(p_array printable, int *array, int low, int high);



#endif /* SORT_H */

#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order.
 *
 * Description: uses the 'Bubble sort' algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = size;
	size_t j = 0;
	size_t swapped = 0;
	int temp = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (i > 0)
	{
		j = 0;
		swapped = 0;
		while (j < (i - 1))
		{
			if (array[j] > array[j + 1])
			{
				/* swap */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped++;

				print_array(array, size);
			}
			j++;
		}
		if (swapped == 0)
		{
			return;
		}
		i--;
	}
}

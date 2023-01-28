#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order.
 *
 * Description: uses the selection sort algorithm.
 *
 * @array: Array of integers.
 * @size: size of @array.
 */
void selection_sort(int *array, size_t size)
{
	int idx, temp, smallest;
	size_t i, j;

	if (!array || size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				idx = j;
			}
		}

		/* swap */
		if (smallest < array[i])
		{
			temp = array[i];
			array[i] = smallest;
			array[idx] = temp;
			print_array(array, size);
		}
	}
}

#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order.
 *
 * Description: uses quick sort algorithm.
 *
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	p_array printable;

	printable.array = array;
	printable.size = size;

	if (!array || size < 2)
	{
		return;
	}

	q_sort(printable, array, size);
}

/**
 * q_sort - quick sort variation.
 *
 * Description: This variation allows the integer array to be
 * printed after every swap. It is necessary because quick sort
 * is recursive and the 'array' parameter keeps changing.
 *
 * @printable: original/initial array that can be printed
 * @array: array of integers (could be a partition)
 * @size: size of array (could be size of the partition)
 */
void q_sort(p_array printable, int *array, size_t size)
{
	int pivot;

	if (!array || size < 2)
	{
		return;
	}

	pivot = partition(printable, array, 0, (size - 1));

	/* left partition */
	q_sort(printable, array, pivot);

	/* right partition */
	q_sort(printable, array + pivot + 1, size - (pivot + 1));
}

/**
 * partition - divides an array into two halves around a pivot
 *
 * Description: Takes the right most element as pivot
 *
 * @printable: original array before any partitions
 * @array: array of integers (could be a partition/subarray)
 * @low : first item of array or subarray
 * @high : last item of array or subarray
 *
 * Return: index of pivot after sorting
 */
int partition(p_array printable, int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high;
	int temp;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] <= pivot && i < high);

		do {
			j--;
		} while (array[j] > pivot && j >= low);

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(printable.array, printable.size);
		}
	}
	temp = array[i];
	array[i] = pivot;
	array[high] = temp;

	if (i < high)
	{
		print_array(printable.array, printable.size);
	}

	return (i);
}

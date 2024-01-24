#include "sort.h"

/**
 * swap - Swap two integers.
 * @a: Integer
 * @b: Integer
 * Return: (void) Swapped integers
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partition an array using a pivot.
 * @array: Array
 * @low: Integer
 * @high: Integer
 * @size: Size of the array (size_t)
 * Return: Index of the pivot (int)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j = high;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}

/**
 * hoare_qsort - Recursively sort an array.
 * @array: Array to be sorted
 * @low: The lowest value in the array
 * @high: The highest value in the array
 * @size: Size of the array
 * Return: void
 */
void hoare_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		if (i > low)
			hoare_qsort(array, low, i, size);
		hoare_qsort(array, i + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Quick Sort Algorithm using Hoare partition.
 * @array: Array to sort
 * @size: Size of the array
 * Return: Sorted array (void)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_qsort(array, 0, size - 1, size);
}

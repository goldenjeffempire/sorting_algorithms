#include "sort.h"

/**
 * partition_array - Partitions a given array using Lomuto scheme.
 * @array: Given array to be sorted.
 * @size: Size of the array.
 * @head: Starting index of the array.
 * @tail: Ending index of the array.
 * Return: Index of the partition.
 */
int partition_array(int *array, size_t size, int head, int tail)
{
	int i, j, piv, temp;

	piv = array[head];
	i = head;
	j = tail;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] <= piv);
		do {
			j--;
		} while (array[j] > piv);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	if (array[head] > array[j])
	{
		temp = array[head];
		array[head] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	return (j);
}
/**
 * lomuto_sort - Implements Lomuto sort recursively.
 * @array: Given array to be sorted.
 * @size: Size of the array.
 * @head: Starting index of the array.
 * @tail: Ending index of the array.
 * Return: Void.
 */
void lomuto_sort(int *array, size_t size, int head, int tail)
{
	int pivot;

	if (head < tail)
	{
		pivot = partition_array(array, size, head, tail);
		lomuto_sort(array, size, head, pivot);
		lomuto_sort(array, size, pivot + 1, tail);
	}
}
/**
 * quick_sort - Sorts an array in ascending order using Quick sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Return: Void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size);
}

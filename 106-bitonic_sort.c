#include "sort.h"
#include <stdio.h>

/**
 * swapint - Swaps indices in an array.
 * @l: Left or low index to swap
 * @r: Right or high index
 */

void swapint(int *l, int *r)
{
	int temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

/**
 * b_merge - Perform bitonic merge on an array slice.
 * @array: Array slice being merged
 * @low: Lowest index
 * @count: Count of elements in the slice
 * @dir: Direction (ascending: 1, descending: 0)
 * @size: Size of the total array for printing
 */

void b_merge(int *array, int low, int count, int dir, size_t size)
{
	int i, n;

	if (count > 1)
	{
		n = count / 2;
		for (i = low; i < low + n; i++)
		{
			if (((array[i] > array[i + n]) && dir == 1) ||
			(dir == 0 && (array[i] < array[i + n])))
				swapint(&array[i], &array[i + n]);
		}
		b_merge(array, low, n, dir, size);
		b_merge(array, low + n, n, dir, size);
	}
}

/**
 * b_sort - Perform bitonic recursive sort on an array.
 * @array: Array to sort
 * @low: Lowest index
 * @count: Count of elements in the slice
 * @dir: Direction (ascending: 1, descending: 0)
 * @size: Size of the total array for printing
 */

void b_sort(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		b_sort(array, low, n, 1, size);
		b_sort(array, low + n, n, 0, size);
		b_merge(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts an array using the bitonic algorithm.
 * @array: Array to sort
 * @size: Size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	b_sort(array, 0, size, 1, size);
}

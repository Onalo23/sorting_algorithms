#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: integer to swap
 * @b: integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 *		using the Shell sort algorithm
 * @array: Array of integers
 * @size: Size of an array
 *
 * Description: The Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, y, z;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (y = gap; y < size; y++)
		{
			z = y;
			while (z >= gap && array[z - gap] > array[z])
			{
				swap_ints(array + z, array + (z - gap));
				z -= gap;
			}
		}
		print_array(array, size);
	}
}

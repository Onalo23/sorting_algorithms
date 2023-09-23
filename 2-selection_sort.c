#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - swaps the values of two integers
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
 * selection_sort - sorts an arrays of integer's ascending order
 * @array: Array of the integer to be sorted
 * @size: Size of an array
 *
 * discription: this print array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *cha;
	size_t y, z;

	if (array == NULL || size < 2)
		return;

	for (y = 0; y < size - 1; y++)
	{
		cha = array + y;
		for (z = y + 1; z < size; z++)
			cha = (array[z] < *cha) ? (array + z) : cha;

		if ((array + y) != cha)
		{
			swap_ints(array + y, cha);
			print_array(array, size);
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_int - swaps the values of two integers
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
 * bubble_sort - sorts an arrays of integer's ascending order
 * @array: Array of the integer to be sorted
 * @size: Size of an array
 *
 * discription: this print array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}

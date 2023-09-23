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
 * lomuto_partition - aranges subordinate of arrays of ints by order
 *			of lomuto partition scheme
 * @array: Array of the ints
 * @size: Size of an array
 * @left: begining index of subordinate to order
 * @right: ending index of subordinate to order
 *
 * discription: overall partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *mouse, up, down;

	mouse = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *mouse)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *mouse)
	{
		swap_ints(array + up, mouse);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Executes/implement quick sort algorithm via recursion
 * @array: Array of the integer to be sorted
 * @size: Size of an array
 * @left: begining index of an array partition to order
 * @right: ending index of an array partition to order
 *
 * discription: Lomuto patition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int kelvin;

	if (right - left > 0)
	{
		kelvin = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, kelvin - 1);
		lomuto_sort(array, size, kelvin + 1, right);
	}
}

/**
 * quick_sort - sorts an arrays of integer's ascending order
 *		via quick sort algorithm
 * @array: Array of the integer to be sorted
 * @size: Size of an array
 *
 * discription: Prints array after each swap with the use
 *	lomuto scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

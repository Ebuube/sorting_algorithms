#include "sort.h"
#include <stdio.h>	/* test */

/**
 * selection_sort - sort an array of integers in ascending order using
 * the Selection sort algorithm.
 * @array: the array to sort
 * @size: the number of elements in the array.
 *
 * Description: The array is printed each time a swap is performed
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t x = 0, y = 0, least = 0;
	int val = 0;

	if (!array || size < 2)
	{
		return;
	}

	for (x = 0; x < size; x++)
	{
		for (y = x, least = y; y < size - 1; y++)
		{/* Find least elements */
			if (array[y + 1] < array[least])
				least = y + 1;
		}
		if (x != least)
		{/* Swap elements */
			val = array[x];
			array[x] = array[least];
			array[least] = val;
			print_array(array, size);
		}
	}
}

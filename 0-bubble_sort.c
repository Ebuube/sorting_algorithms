#include "sort.h"

/**
 * bubble_sort - sort an arrray of integers in ascending order using Bubble Sort
 * algorithm
 * @array: array to sort
 * @size: size  of the array
 *
 * Description: The array is printed each time a swap is made
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t a = 0;
	size_t b = 0;
	int dummy = 0;

	if (!array)
	{
		return;
	}

	for (a = 0; a < size; a++)
	{
		for (b = 1; b < size; b++)
		{
			if (array[b] < array[b - 1])
			{
				dummy = array[b];
				array[b] = array[b - 1];
				array[b - 1] = dummy;
				print_array(array, size);
			}
		}
	}
}

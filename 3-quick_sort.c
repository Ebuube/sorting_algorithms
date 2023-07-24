#include "sort.h"

int *qs(int *array, size_t lower, size_t upper, size_t size);
int partition(int *array, size_t lower, size_t upper, size_t size);
int *swap(int *array, size_t pos_1, size_t pos_2, size_t size);

/**
 * quick_sort - sort an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: the array to sort
 * @size: size of the array
 * Return: return nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	qs(array, 0, size - 1, size);
}

/**
 * KS - sort a partition of an array using the Quick sort algorithm
 *
 * @array: the array to sort
 * @lower: the lower bound of the array, inclusive
 * @upper: the upper bound of the array, inclusive
 * @size: the number of elements in the array
 *
 * Return: the array with the sorted partition, if successful
 * else, return NULL
 */
int *qs(int *array, size_t lower, size_t upper, size_t size)
{
	size_t pivot = 0;

	if (array == NULL ||
		upper > size ||
		upper <= lower)
	{
		return (NULL);
	}

	if (size < 2)
	{/* No need to sort an empty or 1-element array */
		return (array);
	}

	/* partition the array and get the pivot index */
	pivot = partition(array, lower, upper, size);

	/* Sort the two partition recursively */
	qs(array, lower, pivot - 1, size);	/* left partition */
	qs(array, pivot + 1, upper, size);	/* right partition */

	return (array);
}

/**
 * partition - divide an array into two partition around a pivot
 * Such that no element in the left partition is greater than
 * any element in the right partition
 *
 * @array: the array to partition
 * @lower: the lower bound of the array
 * @upper: the upper bound of the array
 * @size: the number of elements in the array
 *
 * Return: the index of the pivot, around which the array was partitioned
 * if successful,
 * else, return -1 (an invalid, negative index)
 */
int partition(int *array, size_t lower, size_t upper, size_t size)
{
	size_t x = 0, tmp_pivot_index = 0;
	int pivot = 0;

	if (array == NULL || upper > size || upper <= lower)
	{
		return (-1);
	}

	if (size < 2)
	{
		return (size);
	}
	pivot = array[upper];	/* Choose last element as pivot */
	tmp_pivot_index = lower - 1;	/* temporary pivot index */

	for (x = lower; x <= upper - 1; x++)
	{
		/* If the current element is less than or equal to the pivot */
		if (array[x] <= pivot)
		{
			tmp_pivot_index += 1;
			swap(array, tmp_pivot_index, x, size);
		}
	}

	/* Move the pivot element to the current pivot position */
	/* between the smaller and larger elements */
	tmp_pivot_index += 1;
	swap(array, tmp_pivot_index, upper, size);

	return (tmp_pivot_index);
}

/**
 * swap - swap the value of two elements in an array
 * @array: the array containing the elements
 * @pos_1: index of element to swap
 * @pos_2: index of element to swap
 * @size: size of the array
 *
 * Description: The array is printed after the swap
 *
 * Return: return the array with the specified elements swapped, if successful
 * else return NULL
 */
int *swap(int *array, size_t pos_1, size_t pos_2, size_t size)
{
	int tmp = 0;

	if (array == NULL ||
		pos_1 > size ||
		pos_2 > size ||
		pos_2 == pos_1)
	{
		return (NULL);
	}

	if (size < 2)
	{/* cannot swap an array with length less than 2 */
		return (array);
	}

	tmp = array[pos_1];
	array[pos_1] = array[pos_2];
	array[pos_2] = tmp;

	/* print the array after each swap */
	print_array(array, size);
	return (array);
}

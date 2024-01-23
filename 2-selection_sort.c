#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 * ascending order using selection sort
 *
 * @array: The array to sort
 * @size: The size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	int min_value;
	int tmp;

	/* Check for valid inputs */
	if (!array || size < 2)
		return;

	/* Selection sort algorithm */
	for (i = 0; i < size; i++)
	{
		min_value = array[i];

	/* Find minimum in unsorted subarray */
		for (j = i + 1; j < size; j++)
	{
		/* Update min if lesser value found */
		if (array[j] < min_value)
		{
			k = j;
			min_value = array[j];
		}
	}

		/* Swap min to current position */
		if (min_value < array[i])
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;

		}
	}
}

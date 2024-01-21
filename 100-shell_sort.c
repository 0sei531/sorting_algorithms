#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 * @array: pointer to array
 * @size: size of the array
 **/
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Calculate the initial gap using the Knuth sequence */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	/* Start with the largest gap and reduce the gap until it becomes 1 */
	for (; gap > 0; gap /= 3)
	{
		/* Perform insertion sort for elements at a specific gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			/* Shift elements that are greater than temp to the right */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			/* Insert temp in the correct position */
			array[j] = temp;
		}
		print_array(array, size);
	}
}


#include "sort.h"

/**
 * partition - Lomuto partition scheme for quicksort
 * @array: pointer to array
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: partition index
 **/
size_t partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int temp;
	size_t i = (size_t)low - 1, j;

	for (j = (size_t)low; j <= (size_t)high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j && array[j] != array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != (size_t)high && array[high] != array[i + 1])
	{
		temp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - recursive implementation of quicksort
 * @array: pointer to array
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 **/
void quicksort(int *array, int low, int high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		if (pi > 0)
			quicksort(array, (int)low, (int)(pi - 1), size);
		quicksort(array, (int)(pi + 1), high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		quicksort(array, 0, (int)(size - 1), size);
	}
}


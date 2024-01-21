#include "sort.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	if (array == NULL)
	{
		/* Handle the case where array is NULL */
		fprintf(stderr, "Error: Array is NULL\n");
		return;
	}

	i = 0;
	while (i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}


#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: array of integers
 * @size: size of the array provided
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	int swap = 1,
	    tmp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	while (swap)
	{
		swap = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				swap = 1;
			}
			/*print_array(array, size);*/
		}
	}
}

#include "sort.h"

void quicksort(int *array, int low, int high);
int partition(int *array, int low, int high);

/**
 * quick_sort - a function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: An array of integers
 * @size: the size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1);
}
/**
 * quicksort - a function to sort the two partitions
 * @array: an array of integers
 * @low: the lowest value
 * @high: the highest value
 *
 * Return: Nothing
 */
void quicksort(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

/**
 * partition - a function to separete tthe into two sides
 * @array: The array
 * @low: the lowest value
 * @high: the highest value
 *
 * Return: the pivot number in the array
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int tmp, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}

	tmp = array[i +1];
	array[i + 1] = array[high];
	array[high] = tmp;
	print_array(array, sizeof(array) + 2);
	return (i + 1);
}

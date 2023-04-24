#include "sort.h"

void quicksort(int *array, size_t size, int low, int high);
int partition(int *array, size_t size, int low, int high);
void swap(int *a, int *b);
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

	quicksort(array, size, 0, size - 1);
}
/**
 * quicksort - a function to sort the two partitions
 * @array: an array of integers
 * @low: the lowest value
 * @high: the highest value
 * @size: size of the array
 *
 * Return: Nothing
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		quicksort(array, size, low, pivot - 1);
		quicksort(array, size, pivot + 1, high);
	}
}

/**
 * partition - a function to separete tthe into two sides
 * @array: The array
 * @low: the lowest value
 * @high: the highest value
 * @size: size of the array
 *
 * Return: the pivot number in the array
 */

int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}
/**
 * swap - a function to swap two integers
 * @a: first int
 * @b: second int
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

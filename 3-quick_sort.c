#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm with Lomuto partition
 *
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursively sorts an array using Quick sort
 *
 * @array: Pointer to the first element of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quicksort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high);

		quicksort_recursive(array, low, pi - 1);
		quicksort_recursive(array, pi + 1, high);
	}
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 *
 * @array: Pointer to the first element of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high + 1);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, high + 1);
	}

	return (i + 1);
}

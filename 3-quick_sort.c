#include "sort.h"

void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * domuto_partition - Order a subset of an array of integers according to
 *                    the lomuto.
 * @array: array of integers.
 * @size:  size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int domuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}



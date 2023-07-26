#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              with Knuth sequence
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	int temp, interval, i, j;

	/* Generate Knuth sequence to determine intervals */
	interval = 1;
	while (interval < (int)size)
		interval = interval * 3 + 1;
	interval = (interval - 1) / 3;

	while (interval > 0)
	{
		/* Perform insertion sort with the current interval */
		for (i = interval; i < (int)size; i++)
		{
			temp = array[i];
			j = i;

			/* Shift elements that are greater than temp */
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}

		/* Print the array after decreasing the interval */
		print_array(array, size);

		/* Update the interval for the next pass */
		interval = (interval - 1) / 3;
	}
}

#include "sort.h"

/**
 * bubble_sort - function to do bubble sort of an array
 *
 * @array: the array to be sorted
 * @size: the size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i,  j;
	int temp;
	int flag;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				flag = 1;

				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}

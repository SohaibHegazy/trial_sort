#include "sort.h"

/**
 * swap_array - function to swap array elements
 *
 * @array: pointer to the array
 * @size: size of the array
 * @a: first element to swap
 * @b: second element to swap
 *
 * Return: void
 */

void swap_array(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array((const int *)array, size);
	}
}

/**
 * part - function to implement lomuto partition
 *
 * @arr: array to be patitioned
 * @size: size of array
 * @lb: start of the array
 * @ub: end of the array
 *
 * Return: pointer to the pivot location
 */

size_t part(int *arr, size_t size, ssize_t lb, ssize_t ub)
{
	int loc, temp, pivot;

	pivot = arr[ub];
	temp = loc = lb;

	while (temp < ub)
	{
		if (arr[temp] < pivot)
		{
			swap_array(arr, size, &arr[temp], &arr[loc]);
			loc++;
		}
		temp++;
	}
	swap_array(arr, size, &arr[loc], &arr[ub]);

	return (loc);
}

/**
 * q_sort - function to do the sorting
 *
 * @arr: the array
 * @size: size of array
 * @lb: the lower bound of the array
 * @ub: the upper bound of the array
 *
 * Return: void
 */

void q_sort(int *arr, size_t size, ssize_t lb, ssize_t ub)
{
	size_t loc;

	if (lb < ub)
	{
		loc = part(arr, size, lb, ub);
		q_sort(arr, size, lb, loc - 1);
		q_sort(arr, size, loc + 1, ub);
	}
}

/**
 * quick_sort - function to sort an array using quick sort
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	q_sort(array, size, 0, size - 1);
}

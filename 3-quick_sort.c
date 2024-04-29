#include "sort.h"
/**
 * swap - swap 2 int value
 * @array: the integers array to sort
 * @size: the size of the array
 * @a: address of the first value
 * @b: address of the socand value
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a  - *b;
		print_array((const int *)array, size);
	}
}
/**
 * Lomuto_partition - partition the array
 * @array: the integer array to sort
 * @size: the size of array
 * @lo: the low index of sort range
 * @hi: the higth index of sort range
 * Return: size_t
 *
 */
size_t Lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivo = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivo)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);
	return (i);
}
/**
 * quicksort - quicksort via  Lomuto partition scheme
 * @array: the integer array to sort
 * @size: the size of array
 * @lo: the low index of sort range
 * @hi: the higet index of sort range
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = Lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - calls quichsort
 * @array: the integer array to sort
 * @size: the size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}

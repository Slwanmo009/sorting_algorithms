#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size <  2)
		return;
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	int *count = malloc((max + 1) * sizeof(int));

	if (count == NULL)
		return;
	for (int i = 0; i <= max; i++)
		count[i] = 0;
	for (size_t i = 0; i < size; i++)
		count[array[i]]++;
	for (int i = 0; i <= max; i++)
		printf("%d ", count[i]);
	printf("\n");
	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];
	int *temp = malloc(size * sizeof(int));
	if (temp == NULL)
	{
		free(count);
		return;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		temp[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (size_t i = 0; i < size; i++)
		array[i] = temp[i];
	free(count);
	free(temp);
}

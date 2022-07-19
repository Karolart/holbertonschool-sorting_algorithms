#include "sort.h"

/**
 * heap_sort - Sorting array
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: 0
 */

void stupify(int *array, int heap, int i, int size)
{
	int lar = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[lar])
		lar = left;
	if (right < heap && array[right] > array[lar])
		lar = right;
	if (lar != i)
	{
		t = array[i], array[i] = array[lar], array[lar] = t;
		print_array(array, size);
		stupify(array, heap, lar, size);
	}
}

/**
 * heapify - Recursive function to sort binary tree
 * @array: array to be sorted as binary tree
 * @end: Last node in binary tree
 * @start: First node of binary tree
 * @size: Size of the array to sort
 * Return: 0
 */

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		stupify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
			print_array(array, size);
		stupify(array, i, 0, size);
	}

}

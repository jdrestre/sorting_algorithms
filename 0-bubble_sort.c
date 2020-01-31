#include "sort.h"

/**
*
*
*
*/

void bubble_sort(int *array, size_t size)
{
	int temp = 0;
	size_t count = 0, i;

	while(size - 1 != count)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
			
		}
		else
		{
			count += 1;
		}
		if (size == i)
		{
			print_array(array, size);
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

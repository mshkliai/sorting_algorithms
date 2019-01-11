#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

void	selection_sort(int *mass, int size)
{
	int	min, index_of_min, buff;

	for (int i = 0; i < size; i++)
	{
		min = INT_MAX;
		index_of_min = i;

		for (int j = i; j < size; j++)
			if (mass[j] < min)
			{
				min = mass[j];
				index_of_min = j;
			}

		buff = mass[i];
		mass[i] = mass[index_of_min];
		mass[index_of_min] = buff;
	}
}

int	main()
{
	int	size = 50000;
	int	*mass = (int*)malloc(sizeof(int) * size);

	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
		mass[i] = rand() % 50000;

	selection_sort(mass, size);

	for (int i = 0; i < size; i++)
		printf("%d\n", mass[i]);
	
	return (0);
}
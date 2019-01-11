#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void	quick_sort(int *mass, int size)
{
	int	i = 0, j = size - 1, buff;
	int	pivot = mass[size >> 1];

	while (i <= j)
	{
		while (mass[i] < pivot) i++;
		while (mass[j] > pivot) j--;
		
		if (i <= j)
		{
			buff = mass[i];
			mass[i] = mass[j];
			mass[j] = buff;

			i++;j--;
		}
	}

	if (j > 0)		quick_sort(mass, j + 1);
	if (size > i)	quick_sort(mass + i, size - i);
}

int	main() 
{
	int	size = 50000;
	int	*mass = (int*)malloc(sizeof(int) * size);

	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
		mass[i] = rand() % 50000;

	quick_sort(mass, size);

	for (int i = 0; i < size; i++)
		printf("%d\n", mass[i]);

	return (0);
}
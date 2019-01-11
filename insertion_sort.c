#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void	insertion_sort(int *mass, int size)
{
	int	key, j;

	for (int i = 1; i < size; i++)
	{
		key = mass[i];
		j = i - 1;
		
		while (j >= 0 && mass[j] > key) 
		{
			mass[j + 1] = mass[j];
			j--;
		}
		mass[j + 1] = key;
	}
}

int	main() 
{
	int	size = 50000;
	int	*mass = (int*)malloc(sizeof(int) * size);

	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
		mass[i] = rand() % 50000;

	insertion_sort(mass, size);

	for (int i = 0; i < size; i++)
		printf("%d\n", mass[i]);

	return (0);
}
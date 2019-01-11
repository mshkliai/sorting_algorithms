#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void	bubble_sort(int *mass, int size)
{
	int	buff;

	for (int i = size; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (mass[j] > mass[j + 1])
			{
				buff = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = buff;
			}
}

int	main() 
{
	int	size = 50000;
	int	*mass = (int*)malloc(sizeof(int) * size);

	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
		mass[i] = rand() % 50000;

	bubble_sort(mass, size);

	for (int i = 0; i < size; i++)
		printf("%d\n", mass[i]);

	return (0);
}
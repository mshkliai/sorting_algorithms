#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void	shell_sort(int *mass, int size)
{
	int	key, j;

	for (int step = size >> 1; step > 0; step >>= 1)
		for (int i = step; i < size; i++)
		{
			key = mass[i];
			j = i - step;

			while (j >= 0 && mass[j] > key)
			{
				mass[j + step] = mass[j];
				j -= step;
			}
			mass[j + step] = key;
		}
}

int	main()
{
	int	size = 50000;
	int	*mass = (int*)malloc(sizeof(int) * size);

	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
		mass[i] = rand() % 50000;

	shell_sort(mass, size);

	for (int i = 0; i < size; i++)
		printf("%d\n", mass[i]);
	
	return (0);
}
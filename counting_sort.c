#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int		get_max(int *mass, int size)
{
	int	max = INT_MIN;

	for (int i = 0; i < size; i++)
		if (mass[i] > max)
			max = mass[i];

	return max < 0 ? 0 : max;
}

void	counting_sort(int *mass, int size)
{
	int	max = get_max(mass, size);
	int	*buffer = (int*)malloc(sizeof(int) * max);

	for (int i = 0; i < max; i++)
		buffer[i] = 0;
	for (int i = 0; i < size; i++)
		buffer[mass[i]]++;

	int j = 0;
	for (int i = 0; i < size; i++)
	{
		while (buffer[j] == 0)
			j++;

		mass[i] = j;
		buffer[j]--;
	}

	free(buffer);
}

int	main() 
{
	int	size = 50000;
	int	*mass = (int*)malloc(sizeof(int) * size);

	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
		mass[i] = rand() % 50000;

	counting_sort(mass, size);

	for (int i = 0; i < size; i++)
		printf("%d\n", mass[i]);
	return (0);
}
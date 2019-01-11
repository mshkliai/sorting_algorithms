#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* merge_sort(int *up, int *down, int left, int right)
{
	if (left == right)
	{
		down[left] = up[left];
		return down;
	}

	int	middle = (left + right) >> 1;

	int	*left_side = merge_sort(up, down, left, middle);
	int	*right_side = merge_sort(up, down, middle + 1, right);

	int	*sorted_mass = left_side == up ? down : up;
	int	l_i = left, r_i = middle + 1;

	for (int i = left; i <= right; i++)
	{
		while (l_i <= middle && r_i <= right)
			sorted_mass[i++] = left_side[l_i] < right_side[r_i] ? left_side[l_i++] : right_side[r_i++];
		while (l_i <= middle)
			sorted_mass[i++] = left_side[l_i++];
		while (r_i <= right)
			sorted_mass[i++] = right_side[r_i++];
	}

	return sorted_mass;
}

int	main() 
{
	int	size = 50000;
	int	*mass = (int*)malloc(sizeof(int) * size);
	int	*mass2 = (int*)malloc(sizeof(int) * size);

	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
		mass[i] = rand() % 50000;

	mass2 = merge_sort(mass, mass2, 0, size - 1);

	for (int i = 0; i < size; i++)
		printf("%d\n", mass2[i]);
	return (0);
}
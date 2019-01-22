#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static void	bounce_down(int *mass, int index, int size)
{
	int	leftChild, rightChild, largestChild;
	int	topElement = mass[index];

	while (index < size >> 1)
	{
		leftChild = (index << 1) + 1;
		rightChild = leftChild + 1;

		if (rightChild < size && mass[rightChild] > mass[leftChild])
			largestChild = rightChild;
		else
			largestChild = leftChild;

		if (topElement >= mass[largestChild])
			break;

		mass[index] = mass[largestChild];
		index = largestChild;
	}
	mass[index] = topElement;
}

static void	make_pyramid(int *mass, int size)
{
	for (int i = size >> 1; i >= 0; i--)
		bounce_down(mass, i, size);
}

static int	remove_top_element(int *mass, int *size)
{
	int	tmp;

	tmp = mass[0];
	mass[0] = mass[--*size];

	bounce_down(mass, 0, *size);

	return tmp;
}

void		pyramid_sort(int *mass, int size)
{
	int old_size, top_element;

	make_pyramid(mass, size);
	old_size = size;

	for (int i = 0; i < old_size; i++)
	{
		top_element = remove_top_element(mass, &size);
		mass[size] = top_element;
	}
}

int	main() 
{
	int	size = 50000;
	int	*mass = (int*)malloc(sizeof(int) * size);

	srand(time(NULL));

	for (int i = 0; i < size; i++)
		mass[i] = rand() % 50000;

	pyramid_sort(mass, size);

	for (int i = 0; i < size; i++)
		printf("%d\n", mass[i]);

	return (0);
}
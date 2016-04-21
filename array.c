#include <stdio.h>

int main (void)
{
	int dim;
	int max = 0;
	
	int i, j;
	printf("hello, please enter a number to represent array dimension:\n");
	while (scanf("%d", &dim) != 1)
	{
		printf("please enter a valid integer like 5 6 or etc\n");
	}
	int array[dim][dim];
	printf("now enter integers to fill in numbers:\n");
	for ( i = 0; i < dim; i++)
	{
		for ( j = 0; j < dim; j++)
		{
			if (scanf("%d", array[i][j]) != 1)
				{
					printf("wow! that was not an integer please fill in matrix again:\n");
					i = 0;
				}
		}
	}
	
	printf("here is your matrix:\n");
	for (i = 0; i < dim; i++)
		{
			printf("\n");
			for (j = 0; j < dim; j++)
				{
					printf("%d ", array[i][j]);
					if (array[i][j] > max) 
						{
							max = array[i][j];
						}
				}
		}
	printf("\n Also maximum value in matrix is %d\n", max);	
	return 0;
}

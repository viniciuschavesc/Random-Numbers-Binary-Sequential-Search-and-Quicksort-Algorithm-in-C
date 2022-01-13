#include <stdio.h>
#include<stdlib.h>
#include <time.h>
 
//Sequential Search
void sequential(int array[], int size, int n)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (array[i] == n)
		{
			printf("%d found in position %d.\n", n, i+1);
			break;
		}
	}
		if (i == size)
			printf("Value not found in the list.\n", n);
}

//Binary Search	
void binary(int array[], int size, int n)
{
	int i, first, last, middle;
	first = 0;
	last = size - 1;
	middle = (first+last) / 2;
 
	while (first <= last) 
	{
		if (array[middle] < n)
			first = middle + 1;
		else if (array[middle] == n)
		{
			printf("%d found in position %d.\n", n, middle+1);
			break;
		}
		else
			last = middle - 1;
		middle = (first + last) / 2;
	}
	if ( first > last )
		printf("Value not found in the list.\n", n);
}
 
int main()
{
 
	//Time variables of time.h library
	clock_t i_0, final;
	 
	//Total time of execution
	double total_time;
	int i = 0, j, n = 0, min, index;
	 
	int vet[10000];
	
	FILE* fptr;
	
	fptr = fopen("Random_Numbers.txt", "r");
	
	while (fscanf(fptr, "%d", &vet[i]) == 1)
	{
		n++;
		i++;
	}
	 
	i_0 = clock();
	 
	//QuickSort Algorithm
	for (i = 0; i < n - 1; i++)
	{
		min = vet[i];
		for (j = i + 1; j < n; j++)
		{
			if (vet[j] < min)
			{
				min = vet[j];
				index = j;
			}
		}
		int temp = vet[i];
		vet[i] = min;
		vet[index] = temp;
	}
		
	final = clock();
		
	total_time = ((float)(final - i_0)) / CLOCKS_PER_SEC;
		
	//Output of QuickSort
	for (i = 0; i < n; i++)
	{ 
		printf("%d ", vet[i]);
		printf("\n\nExecution time of QuickSort Algorithm = %f", total_time);
	}
	
	int num, size;
	size = n;
	printf("\n\nEnter a value to search for:\n");
	scanf("%d", &num);
	printf("Sequential Search: \n");
	sequential(vet, n, num);
	printf("\nBinary Search: \n");
	binary(vet, n, num);
	 
	return 0;
}

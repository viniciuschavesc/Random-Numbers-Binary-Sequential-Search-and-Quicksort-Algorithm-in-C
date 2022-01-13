#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
 
#define NUM 10000
#define MAX 10000
 
int main() 
{ 
	FILE *fn;
 	int n;

	fn=fopen("Random_Numbers.txt","w");

	srand(time(NULL));

	for (int i=1; i <= NUM; i++)
	{
		n = 1 + (rand() % MAX);
		fprintf(fn, "%d ", n);
	}
 
	fclose(fn);
	
	return 0;
} 

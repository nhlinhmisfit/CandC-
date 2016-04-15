#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define	MAX	400

int InsertionSort(int base[], int sz );
int ShellSort(int base[], int n);
int	QuickSort(int pa[],int first, int last);
int main( void ){
	int ary1[MAX],ary2[MAX];
	int i;
	int loops;
	srand((unsigned int)time(NULL));
	for(i=0;i<MAX;++i){	ary1[i] = rand()%1001;}
	memcpy(ary2,ary1,sizeof(ary1));

	printf("Array Size : %d \n", MAX);
	loops = InsertionSort(ary1,MAX);
	printf("Insertion Sort : %d loops \n", loops);
	loops = ShellSort(ary2,MAX);
	printf("Shell Sort : %d loops \n", loops);


	return 0;
}
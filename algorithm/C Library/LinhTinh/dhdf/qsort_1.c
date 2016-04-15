
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	Swap(int *pa, int *pb);
static	int	Partition(int pa[], int first, int last){
	int i,j,pivot;
	i = first-1;
	pivot = pa[last];
	for(j=first;j<last;++j){
		if( pa[j] <= pivot ){
			++i;
			Swap( pa+i, pa+j );
		}
	}
	Swap( pa+i+1, pa+last );
	return i+1;
}
int	QuickSort(int pa[],int first, int last){
	int	mid;
	if( first < last ){
		// search pivot index and some sort
		mid = Partition(pa,first,last);	// <- very important

		// segment array sort
		QuickSort(pa,first,mid-1);	// left seg array
		QuickSort(pa,mid,last);	// right seg array
	}
	return 0;
}
int main_3( void ){
	int datas[20] = {0};
	int i;
	int mid;// pivot_index
	srand((unsigned int)time(NULL));
	for(i=0;i<20;++i)	{	datas[i] = rand()%101;	}

	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");
	QuickSort(datas,0,19);
	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");

	return 0;
}


int main_2( void ){
	int datas[20] = {0};
	int i,j;
	int mid;// pivot_index
	srand((unsigned int)time(NULL));
	for(i=0;i<20;++i)	{	datas[i] = rand()%101;	}
	mid = 19;
	for(i=0;mid && i<20;++i){
		mid = Partition(datas,0,mid );
		for(j=0;j<20;++j)	{	printf("%d ", datas[j]);	}
		printf("\n");
		getchar();
	}

	return 0;
}

int main_1( void ){
	int datas[20] = {0};
	int i;
	int mid;// pivot_index
	srand((unsigned int)time(NULL));
	for(i=0;i<20;++i)	{	datas[i] = rand()%101;	}

	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");

	mid = Partition(datas,0,19);
	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");

	Partition(datas,0,mid-1);
	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");
	Partition(datas,mid,19);
	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");

	return 0;
}



int	Swap(int *pa, int *pb){
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
	return 0;
}

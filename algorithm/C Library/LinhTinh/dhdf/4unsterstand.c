
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int set_random(int datas[],int size){
	int i;
	for(i=0;i<size;++i)	datas[i] = rand()%101;
	return 0;
}
int print(int datas[],int size){
	int i;
	for(i=0;i<size;++i)	printf("%d  ", datas[i]);
	printf("\n");
	return 0;
}

int ShellSortDemo(int a[], int size){
	int	buf[20]={0};
	int i,j;
	int interval = size;

	while(interval>=1){
		interval = interval / 2;
		j = 0;
		for(i=0;i<size;i+=interval){
			buf[j++] = a[i];
		}
		// but index of buf vs index of datas is different
		print(buf, j);
//		InsertionSort(buf,j);
	}

	return 0;
}
int main( void ){
	int datas[20]={	1,12,3,4,15,6,7,18,9,10,
					11,2,13,14,5,16,17,8,19,20};

	srand((unsigned int)time(NULL));	set_random( datas, 20 );
	print(datas,20);
	ShellSortDemo(datas,20);
	print(datas,20);
	return 0;
}

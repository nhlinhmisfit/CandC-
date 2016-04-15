
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

int IntervalSort(int ar[], int size, int start, int interval);
int ShellSort(int base[], int n);
int main( void ){
	int datas[20]={	1,12,3,4,15,6,7,18,9,10,
		11,2,13,14,5,16,17,8,19,20};

	//	srand((unsigned int)time(NULL));	set_random( datas, 20 );
	print(datas,20);
	ShellSort(datas,20);
	print(datas,20);
	return 0;
}
// shell sort funtion

// to explain algorithm with english
int IntervalSort(int a[], int start, int sz, int interval){
	int i;
	int p;
	int temp;
	int count = 0;
	for(i=start+interval;i<sz;i+=interval){
		p = i;
		temp = a[i];
		while( p>0 && a[p-interval] > temp ){
			a[ p ] = a[p-interval];
			p-=interval;
			++count;
		}
		a[p] = temp;
	}
	return count;
}
int ShellSort(int base[], int n){
	int interval;
	int i;
	int count=0;
	interval = n;//20
	while (interval >= 1){
		interval = interval / 2;//10 5 2 1 0
		for (i = 0; i < interval; i = i + 1) {
			//insertion sort for segment array
			count += IntervalSort(base, i, n, interval);
			//			print(base,n);
			//			getchar();
		}
		printf("end interval[%d]---------------------\n",interval);
	}
	printf("total count of loop %d\n", count);
	return 0;
}

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

int IntervalSort(int ar[], int size, int start, int interval);
int ShellSort(int base[], int n);
int main( void ){
	int datas[20]={	1,12,3,4,15,6,7,18,9,10,
		11,2,13,14,5,16,17,8,19,20};

	//	srand((unsigned int)time(NULL));	set_random( datas, 20 );
	print(datas,20);
	ShellSort(datas,20);
	print(datas,20);
	return 0;
}
// shell sort funtion

// to explain algorithm with english
int IntervalSort(int a[], int start, int sz, int interval){
	int i;
	int p;
	int temp;
	int count = 0;
	for(i=start+interval;i<sz;i+=interval){
		p = i;
		temp = a[i];
		while( p>0 && a[p-interval] > temp ){
			a[ p ] = a[p-interval];
			p-=interval;
			++count;
		}
		a[p] = temp;
	}
	return count;
}
int ShellSort(int base[], int n){
	int interval;
	int i;
	int count=0;
	interval = n;//20
	while (interval >= 1){
		interval = interval / 2;//10 5 2 1 0
		for (i = 0; i < interval; i = i + 1) {
			//insertion sort for segment array
			count += IntervalSort(base, i, n, interval);
			//			print(base,n);
			//			getchar();
		}
		printf("end interval[%d]---------------------\n",interval);
	}
	printf("total count of loop %d\n", count);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int IntervalSort(int a[], int start, int sz, int interval){
	int i;
	int p;
	int temp;
	int count =0;
	for(i=start+interval; i<sz; i+=interval) 
	{
		p = i;	
		temp = a[i];
		while( p > 0 && a[p-interval] > temp )
		{
			a[ p ] = a[p-interval];
			p-=interval;
			++count;
		}
		a[p] = temp;
	}
	return count;
}
int print(int datas[],int size){
	int i;
	for(i=0;i<size;++i) printf("%d ", datas[i]);
	printf("\n");
	return 0;
}
int ShellSort(int base[], int n){
	int interval;
	int i;
	int count=0;
	interval = n;//20
	while (interval >= 1){
		interval = interval / 2;
		for (i = 0; i < interval; i = i + 1) {
			count+=IntervalSort(base, i, n, interval);
			print(base,n);
			 getchar();
		}
		printf("end interval[%d]------------------\n",interval);
	}
	printf("count....................%d\n",count);
	return 0;
}
int shellsortdemo(int a[], int size)
{
	int buf[20] = {0};
	int i, j;
	int interval = size/2;
	 j =0;
	for(i =0; i < size; i += interval)
	{
		buf[j++] = a[i];
	}
	print(buf, j);

	return 0;
}
int main()
{
	int data[20]={1,23,24,12,5,2,7,3,6,8,9,2,10,11,23,65,36,65,25,87};
	print(data,20);
	// InsertionSort(data,20);

	//ShellSort(data,20);
	shellsortdemo(data,20);
	print(data,20);
	return 0;
}
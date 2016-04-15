#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	ARY_SIZE	20
// left array [first] ~ [mid]	i
// right array [mid+1] ~ [last]	j
// merge array [first] ~ [last] t

// make merge function to 15:00pm i will check  your code at 15:30pm
int merge(int pa[], int first, int mid, int last){
	int i,j,t;
	int	temp[ ARY_SIZE * 2 ];// i guess -> dynamic array

	i=first;
	j=mid+1;
	t=0;
	while( i<=mid && j<=last ){
		if( pa[i] <= pa[j] ){
			temp[t] = pa[i];
			++i;
		}else{	// pa[i] >= pa[j]
			temp[t] = pa[j];
			++j;
		}
		++t;
	}
	// save remain value
	while(i<=mid)	temp[t++] = pa[i++];
	while(j<=last)	temp[t++] = pa[j++];

	// copy array pa <- temp
	j = first;
	for( i=0;i<t;++i ){
		pa[j++] = temp[i];
	}
	// j [first] ~ [last]
	// memcpy(pa, temp, sizeof(int)*t)
	return 0;
}
int	MergeSort(int pa[],int first, int last){
	int mid;
	if( first < last ){
		mid = (first+last)/2;	//(first+last+1)/2
		MergeSort(pa,first,mid);
		MergeSort(pa,mid+1,last);
		merge(pa,first,mid,last);	// sorting and merge array
	}
	return 0;
}
int main( void ){
	int	datas[ARY_SIZE]={0};
	int i;
	for(i=0;i<ARY_SIZE;++i){	datas[i] = rand()%101;	}
	for(i=0;i<ARY_SIZE;++i){	printf("%d ", datas[i]);	}printf("\n");
	MergeSort(datas,0,ARY_SIZE-1);
	for(i=0;i<ARY_SIZE;++i){	printf("%d ", datas[i]);	}printf("\n");
	return 0;
}

int main_10( void ){
	int ary1[10]={1,5,8,10,12,23,26,38,40,41};//already sorted
	int ary2[10]={3,6,9,11,13,22,27,37,39,44};
	int datas[20] = {0};// remember this size
	int i,j;
	//int mid;// pivot_index
	//srand((unsigned int)time(NULL));
	//for(i=0;i<20;++i)	{	datas[i] = rand()%101;	}
	{// datas = ary1 + ary2
		int	idx=0;
		i = j = 0;
		while( i<10 && j<10 ){
			if( ary1[i] <= ary2[j] ) {
				datas[idx] = ary1[i];
				++idx;
				++i;
			}else{
				datas[idx] = ary2[j];
				++idx;
				++j;
			}
		}
		while(i<10)	datas[idx++] = ary1[i++];
		while(j<10)	datas[idx++] = ary2[j++];

	}
	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");

	return 0;
}


#include "DnA.h"

#define	MAX	20
int size;
int sorted[MAX];
int temp[20];
int		Merge(int a[], int first, int mid, int last){
	int i, j, t;
	int p;

	i = first;
	j = mid+1;
	t = i;
	while(i<=mid && j<=last){
		if( a[i] <= a[j] ){
			temp[t++] = a[i++];
		}else{
			temp[t++] = a[j++];
		}
	}
	while( i<= mid )	temp[t++] = a[i++];
	while( j<= last )	temp[t++] = a[j++];

	for(i = first; i<= last ; i++){
		a[i] = temp[i];
	}
	return 0;
}

int MergeSort(int a[], int first, int last){
	int mid;
	printf("%d-%d:", first, last);PrintStep(a,10,first,last);
	if( first < last ){
		mid = (first+last)/2;
		MergeSort(a,first, mid);
		MergeSort(a,mid+1, last);
		Merge(a, first, mid, last);
	}
	printf("%d-%d:", first, last);PrintStep(a,10,first,last);
	return 0;
}

#include	"DnA.h"

int	Partition(int a[], int first, int last){
	int pivot;
	int i,j;
	pivot = a[last];	// 마지막 요소의 값을 기준값으로 선택
	i = first - 1;		// 정렬된 요소 번호
	for(j=first;j<last;j++){	// 첫번째 요소에서부터
		if(a[j] <= pivot ){		// 기준값보다 작은 요소가 있으면 왼쪽(i)으로 이동(교환) 
			++i;
			SWAP(a[i],a[j]);	
		}
	}
	//i번 요소까지 기준값 보다 작은 값들이 이동된 상태가 된다.
	SWAP(a[i+1],a[last]);
	return i+1;//	기준값이 이동된 요소
}

int QuickSort(int a[], int first, int last){
	int mid;
	printf("%d-%d:", first, last);PrintStep(a,10,first,last);
	if( first < last ){
		mid = Partition(a, first, last);
		QuickSort(a, first, mid-1);
		QuickSort(a, mid+1, last);
	}
	printf("%d-%d:", first, last);PrintStep(a,10,first,last);
	return 0;
}

int	Quick_Sort(int a[], int left, int right){
	int i,j;
	int pivot,t;
	if(left < right ){
		pivot = a[(left+right)/2];	// 중간 요소값을 기준값으로 선택
		i = left-1;
		j = right+1;
		while(1){
			while( a[++i] < pivot );
			while( a[--j] > pivot );
			if( i>=j )	break;	//i와 j 가 역전(교차)되면
			t=a[i];	a[i] = a[j];	a[j] = t;
		}
		Quick_Sort(a, left, i-1);// always mid-1
		Quick_Sort(a, j, right);	// mid or mid+1
	}
	return 0;
}

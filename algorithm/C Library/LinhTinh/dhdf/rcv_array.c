#include "src/DnA.h"

// to search max value in array(1D)
int	max_array(int a[], int size){// a[] == *a
	int	length;// numbers of element
	int max;
	int i;
	length = size;
	max = a[0];
	for(i=1;i<length;++i){
		if( a[i] > max ){
			max = a[i];//= i
		}
	}
	return max;
}
int max_array_rcv_pointer(int a[],int size,int *p){
	static int max = 0;
	if( p == a+size ){// address of last value
		return max;
	}
	if( a == p )	max = *p;
	else{
		if( *p > max ){
			max = *p;//= i
		}
	}
	return	max_array_rcv_pointer(a,size,p+1);//than ++p p++
}
int max_array_rcv(int a[], int i, int size){
//	int length = size;
	static	int max = 0;	
	if( i == size-1 ){	// index's max is 19
		return max;
	}
	if( i == 0 )	max = a[i];
	else{
		if( a[i] > max ){
			max = a[i];//= i
		}
	}
	return	max_array_rcv(a, ++i, size);

}
// preprocessor -> compile -> link ->relocate - create exe
int main(void){
	int numbers[20];
	int i;					
	for(i=0; i<20 ; ++i ){
		numbers[i] = rand()%101;// 0~100
		printf("%d  ", numbers[i]);
	}

	printf("\nMax %d \n", max_array(numbers,20));

	printf("\nMax %d \n", max_array_rcv(numbers,0,20));


	return 0;
}
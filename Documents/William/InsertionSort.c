
#include <stdio.h>
#include <stdlib.h>

int print(int datas[],int size){
	int i;
	for(i=0;i<size;++i)	printf("%d  ", datas[i]);
	printf("\n");
	return 0;
}

int	InsertionSort(int ar[], int size);
int main( void ){
	int datas[20]={	1,12,3,4,15,6,7,18,9,10,
					11,2,13,14,5,16,17,8,19,20};
	print(datas,20);
	InsertionSort(datas, 20);
	print(datas,20);
	return 0;
}

int	InsertionSort(int ar[], int size){

	int i,j;
	int temp;
	int insert_index, target_index;

	for(i=2;i<20;++i){
		target_index = i;
		temp = ar[target_index];
		j = target_index-1;
		while( j>=0 ){
			if( ar[j] < temp )
			{
				insert_index = j+1;
				break;
			}
			--j;
		}
		printf("insert_index is %d \n", insert_index);
		getchar();

		// moving elements
		for(j=target_index; j > insert_index;--j){
			ar[j] = ar[j-1];
		}
		// insert target value( index 17 )
		ar[insert_index ] = temp;// ar[target_index]

	}//end for statement

	return 0;
}
// we want insert to ar[1] ar[5]
//	temp = ar[5];
//	for(i=4;i >= 1;--i){
//		ar[i+1] = ar[i];
//	}
//	ar[i+1] = temp;

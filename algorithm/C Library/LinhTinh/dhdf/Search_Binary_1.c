// concept of Searching
#include <stdio.h>
#include <stdlib.h>
// to searching number what you think
int main( void ){
	int	uNumber;	// computer search this value
	int min = 1;
	int max = 100;
	int call;	// computed by computer
	int resp;
	printf("Input your number : ");
	scanf("%d", &uNumber);
	while(1){
		call = (min+max)/2;
		printf(" Call : %d \n", call );
		printf("Input your answer [1]Down [2]Up [0]Correct!!: ");
		scanf("%d", &resp);
		if( resp == 0 ){
			printf("%d eqal to %d \n", call, uNumber );
			return 0; // exit(1);
		}
		if( resp == 1 ){
			max =  call;
		}
		if( resp == 2 ){
			min = call;
		}
	}


	return 0;
}

// we will search integer value within array
// array is structure random access
//int main_1( void ){
//	int	numbers[10] = { 2,7,3,9,5,7,12,10,9,11};	// unsorted array
////	int	numbers[10] = { 1,2,3,4,5,6,7,8,9,10};	sorted array
//	int key;
//	int i;
//
//	printf("Searching value : ");
//	scanf("%d", &key);
//
//	{
//		int i;
//		for(i=0;i<10;++i){
//			if( numbers[i] == key ){
////				return i, numbers[i], numbers+i
//			}
//		}
//	}
//// searching speed array high than linked list
//	{
//		int i;
//		for(i=9;i>=0;--i){
//			if( numbers[i] == key ){
//				return i, numbers[i], numbers+i
//			}
//		}
//	}
//
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>	//srand, rand
//#include <time.h>	//time()
//// Sorting algorithms based Array
//int print(int a[]){
//	int i;
//	for(i=0;i<20;++i){
//		printf("%d	", a[i] );
//	}
//	printf("\n");
//	return 0;
//}
//int insertionsort(int ar[], int size);
//int main( void){
//	int	datas[20]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
//	int i;
//
//	srand( (unsigned int)time(NULL));// seed changer
//	for(i=0;i<20;++i){
//		//		datas[i] = rand()%101;
//	}
//	printf("\n");
//
//	print(datas);
//
//	{// Selection Sorting
//		//sort process, 		// search max index number 0 - 19
//		int i,j;
//		int max;
//		int count = 0;
//		for(j=0;j<19;++j){// start index
//			max = j;
//			for(i=max+1;i<20;++i){
//				//				if( datas[i] >= datas[max] ){
//				if( datas[i] <= datas[max] ){
//					max = i;
//				}
//			}
//			{//swap
//				int temp;
//				temp = datas[j];
//				datas[j] = datas[max];
//				datas[max] = temp;
//				count++;
//			}
//		}
//		printf("ccount of swap : %d \n", count);
//	}
//
//	print(datas);
//	return 0;
//}
//
//int insertionsort(int ar[], int size)
//{
//
//	return 0;
//}
//
//
//

//#include <stdio.h>
//#include <stdlib.h>
//// to search max value in array(1D)
//
//int maxarray(int a[], int size) //a[] == *a
//{
//	int length; //numbers of element
//	int max;
//	int i;
////	length = sizeof(a); // cannot compute array size
//	length = size; 
//
//	max = a[0];
//	for(i =0; i < length;++i)
//	{
//		if (a[i] >max) 
//		{
//			max = a[i];// = i;
//			//max = i;
//		}
//	}
//	return max;
//}
//int maxarray_rcv(int a[], int i, int size)
//{ 
//	static int max =0; // this funct every called max be init
//	if(i== size -1)
//	{
//		return max;
//	}
//	if( i == 0) max = a[i];
//	else
//	{
//		if (a[i] >max) 
//		{
//			max = a[i];// = i;
//			//max = i;
//		}
//	}
//	return maxarray_rcv(a, ++i,size);
//	//return 0;
//
//}	
//int maxarray_pointer(int a[], int size, int *p)
//{
//	static int max =0;
//	if( p ==a + size ) // address of last value
//	{
//		return max;
//	}
//	if( a == p) max = *p;
//	else
//	{
//		if (*p >max) 
//		{
//			max = *p;// = i;
//			//max = i;
//		}
//	}
//	return maxarray_pointer(a, size,p+1);
//	
//}
//int main(void)
//{
//	int numbers[20];
//	int *p = 0 ;
//	{
//		int i;
//		for(i =0; i< 20; ++i)
//		{
//			numbers[i] = rand()%101;
//			printf("%d ", numbers[i]);
//		}
//		printf("Max %d \n",maxarray(numbers,20));
//		printf("\nMax %d \n",maxarray_rcv(numbers,0,20));
//		printf("\nMax %d \n",maxarray_pointer(numbers,0,p));
//	}
//	return 0;
//}
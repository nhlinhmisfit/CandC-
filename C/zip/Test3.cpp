#include<stdio.h >
#include "conio.h"
#define maxarray 5
void DispFunc(int * iArray, int iArraysize)
{

	printf("iArray : %p\n", iArray);
	printf("&iArray : %p\n", &iArray);
	
	printf("sizeArray :%d\n",sizeof(iArray));
	printf("sizeArray[0] :%d\n",sizeof(iArray[0]));

	for (int i= 0; i < iArraysize; ++i)
	{
		printf("iArr[%d] = %d\n", i, iArray[i]);
	}
	printf("\n");
}
void main()
{
//	int x; 
//	int y;
//	int iResult;
//
//	printf("&x  - >  %p\n", &x);
//	printf("&y  - >  %p\n", &y);
//	printf("&iResult  - >  %p\n", &iResult);
////	printf("&x1")
//	x= 10;
//	y= 20;
//	iResult = x +y;
//
//	printf("%d +%d = %d\n", x, y,iResult);
//	getch();

	//int iValue =0;
	int iArray1[maxarray];
	int iArray2[10];
	printf("size array1 :%d\n",sizeof(iArray1));
	printf("size array1[0]: %d\n",sizeof(iArray1[0]));
	
	//printf("iArray : %p\n", iArray);
	for (int i=0 ; i <sizeof(iArray1)/sizeof(iArray1[0]); ++i)
	{

		iArray1[i] = i;

	}
	for (int i=0 ; i <sizeof(iArray2)/sizeof(iArray2[0]); ++i)
	{

		iArray2[i] = i;

	}
	DispFunc(iArray1,sizeof(iArray1)/sizeof(iArray1[0])) ;
	DispFunc(iArray2,sizeof(iArray2)/sizeof(iArray2[0])) ;

	//printf("iValue =%d\n",iValue);
	/*for (int i= 0; i < 10 ;  ++i)
	{
	printf("iArray[%d] = %d\n" ,i ,iArray[i]);

	}*/
//	printf("%d\n",iValue);
	//stupid code because if we make a funtion 

}
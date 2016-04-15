#include <stdio.h>
#include < conio.h>

int MyFunc( int x , int y)
{
	int iResult;
	 iResult = x +y;
	 return iResult;
}
void swap( int *px, int *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}
void swap1( int **ppx, int **ppy)
{
	int *temp = *ppx;
	*ppx = *ppy;         // change point value
	*ppy = temp;
}

void main()
{
	/*int iValue;
	iValue = MyFunc(10, 20 );
	printf( "iValue : %d\n", iValue);*/

	int x =10; 
	int y =20;

	int *pValuex = &x;

	int *pValuey = &y;

	printf("x : %d\n", x);
	printf("y : %d\n",y);
	printf("&x : %p\n", &x);
	printf( "&y : %p\n", &y);
	
	printf( "pValuex : %p\n", pValuex);
	printf( "pValuey : %p\n", pValuey);
	printf( "&pValuex : %p\n", &pValuex);
	printf( "&pValuey : %p\n", &pValuey);

	swap1(&pValuex, &pValuey);

	printf("x : %d\n", x);
	printf("y : %d\n",y);
}
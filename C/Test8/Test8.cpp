#include <stdio.h>
#include <malloc.h>

void MakeArray(int **ppiArray, int *piArraySize)
{
	printf("size : ");
	scanf("%d", piArraySize);
	*ppiArray = ( int *)malloc(sizeof(int) * (*piArraySize));
}
void main()
{
	int * iArray;
	int iArraySize;

	MakeArray(&iArray, &iArraySize);

 	 for (int i =0; i < iArraySize ; ++i)
	 {
		 iArray[i] =i;
	 }
	 for (int i =0; i < iArraySize ; ++i)
	 {
		 printf( "iArray[%d] = %d\n",i, iArray);
	 }
}
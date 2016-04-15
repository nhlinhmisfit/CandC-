#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(void)
{
	//generate 10 string 
	//array's start address 10
	// we need 10 pointer 
	//and array of poniter
	char *pString[10]= {0}; //array of pointer
	int i;
	int length; 
	char in_buffer[512] = {0};

	for (i =0; i<10; ++i){
		gets(in_buffer);
		length = strlen(in_buffer);

		//calloc allocate array in memory
		pString[i] = (char *)calloc(sizeof(char ),length);
		strcpy(pString[i],in_buffer);
	}

	for (i =0; i<10; ++i){
		printf("%s \n", pString[i]);

	//	pString[i] = calloc(sizeof(char),length);
	}
	for( i= 0; i< 10; ++i)
	{
		free(pString[i]);
	}

	return 0;
}
//int main_1(void)
//{
////	int *pArray = NULL; // = 0;
//	int * dynamic_ar =NULL;
//	int i;
//	int numbers;
//	printf("how much number: ");
//	scanf("%d", &numbers);
//	for(i= 0; i <numbers; ++i)
//	{
//		dynamic_ar = (int *)realloc(dynamic_ar,sizeof(*dynamic_ar)*(i+1));
//
//		*(dynamic_ar +i)= rand()%1000;
//	}
//	for( i =0 ;i<numbers;++i)
//	{
//		printf("%d %d \n",i, dynamic_ar[i]);
//	}
//	return 0;
//}
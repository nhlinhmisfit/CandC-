//#include <stdio.h>
//#include <stdlib.h>
//
//int *searchvalue(int key, int a[],int size)
//{
//	if(size ==0)
//	{
//		return NULL;
//	}
//	if(*a == key)
//	{
//		return a;
//	}
//	return searchvalue(key,a+1,size);
//}
//int main(void)
//{
//	int row[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//	int *rs;
//	rs =searchvalue(18,row,20);
//	if(rs== NULL)
//	{
//		printf("Not exits.\n");
//	}
//	printf("%d \n", *rs);
//	return 0;
//}
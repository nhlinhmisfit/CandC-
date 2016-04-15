//#include <stdio.h>
//
//int print_array(int *pt, int cur, int size)
//{
//	int i = cur;
//	if(i ==size)
//	{
//		return 1;
//	}
//	printf("[%d]  %d\n",i, pt[i]);
//	print_array(pt, i+1,size);
//	return 0;
//}//use index
//
//int print_array1(int *pa, int *end)
//{
//	if(pa == end )
//	{
//		return 1;
//	}
//	print_array1(pa+1, end);
//	printf("%d - %d\n",end -pa,*pa); //or end - pa -1 is out from 0
//	
//	return 0;
//}//use address
//int printarray(int *pa,  int left, int right)
//{
//	int mid = (right + left +1)/2;
//
//	printf("%d -%d [",left, right);
//	{
//		for(int i = left ; i <= right; ++i)
//		{
//			printf("%d.", pa[i] );
//		}
//		printf("]\n");
//	}
//	if( left == right )
//	{
//		return 1;
//	}
//
//	printarray(pa, left, mid -1);
//	printarray(pa, mid, right); // seg2
//	
//	return 0;
//}
//int print(int *pa, int left, int right)
//{
//	int mid = (left +right +1) /2;
//	if(left == right)
//	{
//		return 1;
//	}
//
//}
//int main(void)
//{
//	int datas[21] ={1,2,3,4,5,6,7,8,9,10,11,
//		12,13,14,15,16,17,18,19,20,21};
//	int cur =0;
//	print_array(datas,cur,21);
////	printarray(datas,0,20);
//	//print_array1(datas+0,datas+21);
//	return 0;
//}
////{
////	int *seg1 = datas +0;
////	int i; 
////	for(i = 0; i <10; ++i)
////	{
////		printf("[%d]%d\n", i , seg1[i]);
////	}
////	printf("\nseg1 array\n");
////}
////{
////	int *seg2 = datas +10;
////	int i; 
////	for(i = 0; i <10; ++i)
////	{
////		printf("[%d]%d\n", i , seg2[i]);
////	}
////	printf("\nseg2 array\n");
////}
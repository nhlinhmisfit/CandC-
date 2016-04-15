//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int uNumber; //computer search this value
//	int min =1;
//	int max =100;
//
//	int call; //computed by computer
//	printf("input your number: ");
//	scanf("%d", &uNumber);
//	while(1){
//		call = (min +max)/2;
//		printf("call: %d \n", call);
//		int resp;
//		printf("input your answer 1[down], 2[up]: ");
//		scanf("%d", &resp);
//		if(resp ==0)
//		{
//			printf("%d equal to %d\n", call, uNumber);
//			return 0;
//		}
//		if(resp ==1)
//		{
//			max =call;
//		}
//		if(resp ==2)
//		{
//			min =call;
//		}
//	}
//	return 0;	
//}
//
//
//
////int main1 ()
////{
////	int numbers[10] = { 2,7,3,9,5,7,12,10,9,11};
////	int numbers[10] = {1,2,3,4,5,6,7,8,9,10};
////	int key;
////	int i;
////	
////	printf("Searching value: ");
////	scanf("%d", &key);
////
////	{
////		int i;
////		for(i= 0; i <10; ++i)
////		{
////			if(numbers[i]== key){
////	//			return i,numbers[i], numbers+i;
////
////			}
////		}
////	}
////	{
////		int i;
////		for(i= 9; i >=0; --i)
////		{
////			if(numbers[i]== key){
////		//		return i,numbers[i], numbers+i;
////
////			}
////		}
////	}
////	return 0;
////}
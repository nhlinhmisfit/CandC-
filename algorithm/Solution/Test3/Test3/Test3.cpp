//#include<stdio.h>
//#include<stdlib.h>
//
//char maparray[15][15] = {
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//};
//typedef struct _node
//{
//	struct _node *link;
//	int from;
//	int to;
//}NODE;
//int display_path(int curr, int target)
//{
//	if(curr == target)
//	{
//		return 1;
//	}
//	
//
//	//for(int i = 0; i <15; ++i)
//	//{
//	//	if(( curr != i) && maparray[curr][i] == 1)
//	//	{
//	//		if(! display_path(i,target))
//	//			break;
//	//	}
//	//	
//	//}
//
//	printf("%d ->\n",curr); 
//	int i=0;
//	if(maparray[curr][0]==1){
//		display_path(i, target);
//	}
//	//printf("%d ->\n",curr); 
//	return 0;
//
//}
//int main(void)
//{
//
//	{
//		int i,j;
//		for(i = 0;i <15; ++i)
//		{
//			for(j =0; j<15; ++j)
//			{
//				if(i!= j) maparray[i][j] = rand() %2;
//			}
//		}
//	}
//	/*{
//		int i,j;
//		for(i = 0; i <15; ++i)
//		{
//			for(j =0; j <15; ++j)
//			{
//				if(maparray[i][j]==1)
//				{
//
//					printf("can move : %d -> %d\n",i,j);
//				}
//			}
//
//		}
//	}*/
//	int currno;
//	int desno;
//	{
//		
//		printf("input your current position no: ");
//		scanf("%d", &currno); fflush(stdin);
//
//
//		printf("\ninput your destination position no: ");
//		scanf("%d", &desno); fflush(stdin);
//
//		printf("Display path [%d] -> [%d]\n", currno, desno);
//		
//	}
//	display_path(currno, desno);
//}
//
//int main2(void)
//{
//	NODE temp ={0};
//	temp.from = 5;
//
//	temp.to = 14;
//	maparray[temp.from][temp.to] =1; // can to go
//
//	{
//		int i,j;
//		for(i = 0;i <15; ++i)
//		{
//			for(j =0; j<15; ++j)
//			{
//				if(i!= j) maparray[i][j] = rand() %2;
//			}
//		}
//	}
//	{
//		int i,j;
//		for(i = 0; i <15; ++i)
//		{
//			for(j =0; j <15; ++j)
//			{
//				if(maparray[i][j]==1)
//				{
//
//					printf("can move : %d -> %d\n",i,j);
//				}
//			}
//
//		}
//	}
//	int currno;
//	int desno;
//	printf("input your current position no: ");
//	scanf("%d", &currno); fflush(stdin);
//
//
//	printf("\ninput your destination position no: ");
//	scanf("%d", &desno); fflush(stdin);
//
//	printf("Display path [%d] -> [%d]\n", currno, desno);
//
//	{
//		int i,j;
//		for(i = 0; i <15; ++i)
//		{
//			if(maparray[currno][i] ==1)
//			{
//				printf("[%d] -> %d\n",currno,i);
//				if(i ==desno) {break;}
//				currno =i;
//
//			for(i = 0; i <15; ++i)
//			{
//				if(maparray[currno][i] ==1)
//				{
//					printf("[%d] -> %d\n",currno,i);
//					currno =i;
//
//				}
//			}
//			/*for(j =0; j <15; ++j)
//			{
//			if(maparray[i][j]==1)
//			{
//			printf("can move : %d -> %d\n",i,j);
//			}
//			}*/
//			}
//		}
//	}
//	return 0;
//}
//
//int main1(void)
//{
//	int position_array[3][3] ={0};
//	int A[3][3]= {1,2,3,4,5,6,7,8,9}; //to give weight at position array
//	//Matrix: A x B= C
//	int B[3][3] = {1,0,0,0,3,0,0,0,1};
//	int C[3][3] = {0};
//
//	int i,j,k;
//	for(k =0; k<3; ++k)
//	{
//
//	for(j=0 ; j<3; ++j)
//	{
//		for(i=0; i<3; ++i)
//		{
//			C[k][j] = 
//				A[k][i] * B[i][j] ; 
//		}
//	}
//	
//	}
//	for(k =0; k< 3 ; ++k)
//	{
//		for(j= 0; j<3; ++j)
//		{
//			printf("%d  ", C[k][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
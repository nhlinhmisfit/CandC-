//
//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <time.h>
//int Swap(int *pa,int *pb)
//{
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//	return 0;
//}
//static int Partition(int pa[],int first,int last)
//{
//	// pivot is pa[last], then stop when j == last
//	int i,j,pivot;
//	i = first -1;
//	j = first;
//	pivot = pa[last];
//
//
//	for (j=first;j<last;++j)
//	{
//		if (pa[j]<=pivot)
//		{
//			++i;
//			Swap(pa+i,pa+j);
//		}
//	}
//	Swap(pa+i+1,pa+last);
//	return i+1;
//}
//
//static int QuickSort(int pa[], int first, int last)
//{
//	int mid;
//	if(first<last)
//	{
//		mid =Partition(pa, first,mid -1);
//		QuickSort( pa, mid,last);
//	}
//	return 0;
//}
//int main(void)
//{
//	int datas[20]= {0};
//
//
//	// 	printf("%d%d\n",datas[2],datas[5]);
//	// 	Swap(datas+2,datas+5);
//	// 	printf("%d%d\n",datas[2],datas[5]);
//
//	srand((unsigned int)time(NULL));
//	int i,j,mid;
//	for(i=0;i<20;i++)
//	{
//		datas[i]=rand()%101;
//	}
//	mid =19;
//	for(i =0;mid && i<20; ++i){
//	{
//	//	printf("%d\n",Partition(datas,0,mid-1));
//		//printf("%d\n",Partition(datas,mid,19));
//		//mid=Partition(datas,first,mid);
//		//mid=Partition(datas,mid,last);
//
//		for( j =0; j<20; ++j)
//		{
//			printf("%d  ", datas[j]);
//		}
//		QuickSort(datas,0,19);
//		printf("\n");
//		getchar();
//	}
//	}
//	return 0;
//}
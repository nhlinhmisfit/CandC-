//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define  asize 20
//int merger(int pa[], int first, int mid, int last)
//{
//	int i, j ,t;
//	int temp[40];
//	i = first;
//	j = mid +1;
//	t  =0;
//
//	while( i <= mid && j<=last)
//	{
//		if(pa[i] < pa[j])
//		{
//			temp[t] = pa[i];
//			++i;
//		}
//		else 
//		{
//			temp[t] = pa[j];
//			++j;	
//		}
//		++t;
//	} //save remain value
//	while (i<=mid) temp[t++] = pa[i++];
//	while (j<=last) temp[t++] = pa[j++];
//
//	//copy array pa < temp
//
//	j = first; 
//	for(i =0; i <t; ++i)
//	{
//		pa[j++] = temp [i];
//
//	}
//	return 0;
//	
//}
//int mergesort(int pa[], int first, int last)
//{
//	int mid;
//	if(first <last)
//	{
//		mid = (first + last )/2; //(first + last+1) /2
//		mergesort(pa, first, mid);
//		mergesort(pa, mid+1, last);
//		merger(pa, first, mid, last);	
//	}
//	return 0;
//}
//int main(void)
//{
//	int data[asize] = {0};
//	int i;
//	for(i = 0; i<asize; ++i) { data[i] = rand() %101;}printf("\n");
//	for(i = 0; i<asize; ++i) { printf("%d ",data[i]); }
//	mergesort(data,0,asize-1);
//	printf("\n");
//	for(i = 0; i<asize; ++i) { printf("%d ",data[i]); }
//	printf("\n");
//	return 0;
//
//}
//int main1( void ){
//	int ary1[10]={1,5,8,10,12,23,26,38,40,41};//already sorted
//	int ary2[10]={3,6,9,11,13,22,27,37,39,44};
//	int datas[20] = {0};// remember this size
//	int i,j;
//	//int mid;// pivot_index
//	//srand((unsigned int)time(NULL));
//	//for(i=0;i<20;++i)	{	datas[i] = rand()%101;	}
//	{// datas = ary1 + ary2
//
//		int	idx=0;
//		i = j = 0;
//		while( i<10 && j<10 ){
//			if( ary1[i] <= ary2[j] ) {
//				datas[idx] = ary1[i];
//				++idx;
//				++i;
//			}else{
//				datas[idx] = ary2[j];
//				++idx;
//				++j;
//			}
//		}
//		while(i<10)	datas[idx++] = ary1[i++];
//		while(j<10)	datas[idx++] = ary2[j++];
//
//	}
//	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");
//
//	return 0;
//}
//

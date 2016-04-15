//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//int Swap(int *pa, int *pb);
//int Partition(int pa[], int first, int last);
// int main(void)
// {
//	 int datas[20]= {1,2,3,4,5,6,7,8,9,10};
//	 int i;
//	 srand((unsigned int)time(NULL)) ;
//	 for(i =0; i <20; ++i)
//	 {
//		 datas[i] = rand() %101;
//	 }
//	 for(i=0; i <20; ++i)
//	 {
//		 printf("%d",datas[i]);
//	 }
//	 return 0;
// }
//
// int Swap(int *pa, int *pb)
// {
//	 int temp;
//	 temp = *pa;
//	 *pa = *pb;
//	 *pb = temp;
//	 return 0;
// }
//
// int Partition(int pa[], int first, int last)
// {
//	 //pivot is pa[last], then stop when j == last
//	 int i, j, pivot;
//	 pivot = pa[last];
//	 j =first;
//	 i=-1;
//	 while(j <last)
//	 {
//		 if(pa[j] < pivot)
//		 {
//			 ++i;
//			 Swap(pa +i, pa +j);
//		 } 
//		 ++j;
//	 }
//	                      
//	 Swap(pa +i+1, pa +last);
//	 return 0;
// }
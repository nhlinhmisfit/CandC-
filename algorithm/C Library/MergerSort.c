#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void ){
	int ary1[10]={1,5,8,10,12,23,26,38,40,41};//already sorted
	int ary2[10]={3,6,9,11,13,22,27,37,39,44};
	int datas[20] = {0};// remember this size
	int i,j;
	//int mid;// pivot_index
	//srand((unsigned int)time(NULL));
	//for(i=0;i<20;++i)	{	datas[i] = rand()%101;	}
	{// datas = ary1 + ary2
		int	idx=0;
		i = j = 0;
		while( i<10 && j<10 ){
			if( ary1[i] <= ary2[j] ) {
				datas[idx] = ary1[i];
				++idx;
				++i;
			}else{
				datas[idx] = ary2[j];
				++idx;
				++j;
			}
		}
		while(i<10)	datas[idx++] = ary1[i++];
		while(j<10)	datas[idx++] = ary2[j++];

	}
	for(i=0;i<20;++i)	{	printf("%d ", datas[i]);	}	printf("\n");

	return 0;
}


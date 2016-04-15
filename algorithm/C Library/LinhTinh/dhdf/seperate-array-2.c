
#include <stdio.h>
/*
	
*/
int	print_array(int	pa[], int left, int right){
	int mid = (right+left+1)/2;
//	int mid = (right+left)/2;
	printf("%d~%d [", left, right);
	{
		int i;
		for(i=left;i<=right;++i){
			printf("%d.", pa[i]);
		}
		printf("] \n");
	}
	if( left == right ){// do well think
		return 1;
	}
	print_array(pa,left,mid-1);	// left side
	print_array(pa,mid,right);	//right side

	return 0;
}
int main( void ){
	int	datas[20] = {1,2,3,4,5,6,7,8,9,10,
		11,12,13,14,15,16,17,18,19,20};

	print_array(datas,0,19);
	return 0;
}
	
	//{
	//	int	*seg1 = datas+0;
	//	int i;
	//	for(i=0;i<10;++i){
	//		printf("[%d]%d ", i, seg1[i]);
	//	}
	//	printf("\nseg1 array \n");

	//}
	//{
	//	int	*seg2 = datas+10;
	//	int i;
	//	for(i=0;i<10;++i){
	//		printf("[%d]%d ", i, seg2[i]);
	//	}
	//	printf("\nseg2 array \n");

	//}


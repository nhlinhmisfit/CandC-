
#include <stdio.h>
/*
	Step1.	Print Array elements with Recursive func
		int	print_array(int	pa[], int cur,	int size){
			int	i = cur;
			if( i == size ){
				return 1;
			}
			printf("[%d]	%d\n", i, pa[i]);// prefix
			print_array(pa, i+1, size);
		//	printf("[%d]	%d\n", i, pa[i]);//postfix
			return 0;
		}
*/
// try use address
int	print_array(int	*pa,	int *end){
	if( pa == end ){
		return 1;
	}
	print_array(pa+1, end);
	printf("%d -	%d\n", end-pa, *pa);
	return 0;
}

int main( void ){
	int	datas[20] = {1,2,3,4,5,6,7,8,9,10,
		11,12,13,14,15,16,17,18,19,20};

	print_array(datas+0,datas+20);
	return 0;
}

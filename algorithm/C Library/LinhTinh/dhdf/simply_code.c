
#include <stdio.h>
/*
	Hint! for difficult man~	
*/
int	print_array(int	pa[], int size){
	int i;
	for(i=0;i<size;++i){
		printf("%d  ", pa[i] );
	}
	printf("\n");
	return 0;
}
int main( void ){
	int	datas[20] = {1,2,3,4,5,6,7,8,9,10,
		11,12,13,14,15,16,17,18,19,20};
	int i;
	int size = 20;	
	for(){
		print_array(datas,size);
		size /= 2;
	}
	print_array(datas,10);
	print_array(datas+10,10);

	print_array(datas,5);
	print_array(datas+5,5);
	print_array(datas+10,5);
	print_array(datas+15,5);

	return 0;
}


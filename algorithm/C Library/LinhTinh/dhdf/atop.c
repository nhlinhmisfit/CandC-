
#include <stdio.h>
#include <stdlib.h>

char	map_array[15][15]={// 0 is cannot 1 is can 
	0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
typedef struct _node{
	struct _node	*link;
	int	from;
	int to;
}NODE;
// this function is Searching path where you want go
// with map_array
// map_array have state value(0 or 1) 
//		0 : can not move
//		1 : cam move
// row index is from(start position)
// col index is to(end position)
int display_path(int from, int to , int target){
	int i;
	if(to > 14 )// think array index range
		return EOF;
	if(current == target){// arrived
		return 1;
	}
	printf("%d ->	\n", current);
	if( map_array[from][to] == 1 )
		display_path( from, ++to , target );
	}
	return 0;
}

//int test_recurv(int v){
//	// do not recursive when you must to process many many many big data
//	printf("%d	\n", v );
//	test_recurv(v);
//	return 0;
//}
//
//int main( void ){
//	
//	test_recurv(10);
//
//	while( 0 ){
//		printf("%d \n", 10 );
//	}
//	return 0;
//}

int main( void ){
	int	curr_no;
	int dest_no;
	//{
	//	int i,j;
	//	for(i=0;i<15;++i){
	//		for(j=0;j<15;++j){
	//			if( i!=j )	map_array[i][j] = rand()%2;
	//		}
	//	}
	//}

	// think your solve 
	{

		printf("input your current position no : ");
		scanf("%d" , &curr_no );	fflush(stdin);

		printf("input your destination position no : ");
		scanf("%d" , &dest_no );	fflush(stdin);

		printf("Display path [%d] -> [%d] \n", curr_no, dest_no);
	}

	display_path(curr_no, dest_no);// recursive function instead of Loop


	return 0;
}

int main_2( void ){
	{
		int i,j;
		for(i=0;i<15;++i){
			for(j=0;j<15;++j){
				if( i!=j )	map_array[i][j] = rand()%2;
			}
		}
	}

	{
		int i, j;
		for(i=0;i<15;++i){
			for(j=0;j<15;++j){
				if( map_array[i][j] == 1 ){
					printf("can move : %d -> %d \n", i, j );
				}
			}
		}
	}

	// think your solve 
	{
		int	curr_no;
		int dest_no;

		printf("input your current position no : ");
		scanf("%d" , &curr_no );	fflush(stdin);

		printf("input your destination position no : ");
		scanf("%d" , &dest_no );	fflush(stdin);

		printf("Display path [%d] -> [%d] \n", curr_no, dest_no);
		{// i show difficult code to you
			// we can use recursive function
			int i,j;
			for(i=0;i<15;++i){
				if( map_array[curr_no][i] == 1 ){
					printf("[%d]	->	%d \n", curr_no,	i );
					if( i== dest_no ){	break;	}
					curr_no = i;
					for(i=0;i<15;++i){
						if( map_array[curr_no][i] == 1 ){
							printf("[%d]	->	%d \n", curr_no,	i );
							if( i== dest_no ){	break;	}
							curr_no = i;
						}
					}
				}
				//for(j=0;j<15;++j){
				//	if( map_array[i][j] == 1 ){
				//		printf("can move : %d -> %d \n", i, j );
				//	}
				//}
			}
		}
	}


	return 0;
}

int main_1( void ) {
	int position_array[3][3]={0};
	int A[3][3] = {1,2,3,4,5,6,7,8,9};// to give weight at position_array
	int B[3][3] = {1,0,0,0,3,0,0,0,1};
	int C[3][3] = {0};
	// Matrix : A x B = C

	int i,j,k;
	// compute matrix multiplication A x B
	for(k=0;k<3;++k){
		for(j=0;j<3;++j){
			for(i=0;i<3;++i){
				C[k][j] += A[k][i] * B[i][j];
			}
		}
	}

	for(k=0;k<3;++k){
		for(j=0;j<3;++j){
			printf("%d	", C[k][j] );
		}
		printf("\n");
	}




	return 0;
}
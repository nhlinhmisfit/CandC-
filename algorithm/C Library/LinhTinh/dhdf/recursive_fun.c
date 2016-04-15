#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( void ){
	int i,j,k;
	int unit = 1;
	int max = 9;

	printf("Dan ( 1 ~ max ) : ");
	scanf("%d", &max);	fflush(stdin);
	printf("dan per line ? : "); 
	scanf("%d", &unit);	fflush(stdin);

	for(i=1;i<=max;i+=unit){
		for(j=1;j<9;++j){
			for(k=0;k<unit;++k){
				if((i+k)<=max){
					printf("%d x %d = %d	", i+k,j,(i+k)*j );
				}
			}
			printf("\n");
		}
	}

	return 0;
}

typedef struct _string_array{
	char	**head;
	int		rows;	//numbers of string
}StringArray;

StringArray	create_random(int	rows){
	StringArray	sa = {0};
	int idx, length, k, random_ch;

	srand((unsigned int)time(NULL));
	printf("Auto creating random string(name) : %d \n", rows);
	sa.head = calloc(rows, sizeof(char*));
	sa.rows = rows;
	for(idx=0;idx<rows;++idx){
		length = rand()%21+10;	// 10 ~ 30 
		sa.head[idx] = calloc(sizeof(char), length+1);
		for(k=0; k<length; ++k){
			random_ch = rand()%26+'a';
			sa.head[idx][k] = random_ch;
		}
		sa.head[idx][length/2] = ' ';
	}
	return sa;
}
int main( void ){
	StringArray	friends={0};
	int idx;

	friends = create_random(16);
	for(idx=0;idx<friends.rows;++idx){
		printf("[%2d]	%s\n", idx+1, friends.head[idx]);
	}

	for(idx=0;idx<friends.rows;++idx){
		if( friends.head[idx] ){
			free(friends.head[idx]);
		}
	}
	return 0;
}
*/
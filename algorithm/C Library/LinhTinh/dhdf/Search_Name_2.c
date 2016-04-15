// data type for searching
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef	struct _person{
	int seq;
	char name[40];
}PERSON;
typedef struct _department{
	int code;
	char name[40];
	PERSON	members[20];
}DEPART;
typedef struct _info{
	int seq;
	char name[40];
}T;

T	Teams[10];
T	Members[20];

DEPART	Departs[10];

/*
	Make search member name
*/

int main( void ){
	char	*DepartName[] = {"A team", "B team", "C team"};
	char	*Name[] = {"unused index","Kim", "jang", "dk", "Phuc"};
	char	key[80]={0};
	int		table[3][3]={0};
	int		*table[3] = {NULL};
	int seq = 0;
// i do not save [0][2], [1][1], [1][2], [2][1], [2][2]
	table[0][0] = 1;
	table[0][1] = 2;
	table[1][0] = 3;
	table[2][0] = 4;

	{
		int i,j;
		int depart_index, name_index;
		for(i=0;i<3;++i){
			printf("depart name :%s \n", DepartName[ i ] );
			for(j=0;j<seq;++j){
				depart_index = table[j][0];
				if( i== depart_index ){
					name_index = table[j][1];
					if( name_index ){
						printf("	%s", Name[ name_index ] );
					}
				}
			}
			printf("\n");
		}
	}


	return 0;
}

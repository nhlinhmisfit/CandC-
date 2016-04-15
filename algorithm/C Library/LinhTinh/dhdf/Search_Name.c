// data type for searching
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main_2( void ){
	char	*DepartName[] = {"A team", "B team", "C team"};
	char	*Name[] = {"Kim", "jang", "dk", "Phuc"};
	char	key[80]={0};
	int		table[100][2];	// [0]Depart's Index [1]Name's Index
	// must be great than numbers of Person
	int seq = 0;
	table[seq][0] = 0;
	table[seq][1] = 0;
	++seq;
	table[seq][0] = 0;
	table[seq][1] = 1;
	++seq;
	table[seq][0] = 1;
	table[seq][1] = 2;
	++seq;
	table[seq][0] = 2;
	table[seq][1] = 3;
	++seq;

	/*"DepartName : ~~~~"
	"	Name, Name, Name"*/

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

	//{
	//	int i;
	//	int depart_index, name_index;
	//	for(i=0;i<seq;++i){
	//		depart_index = table[i][0];
	//		printf("%s \n", DepartName[ depart_index ] );
	//		name_index = table[i][1];
	//		printf("%s \n", Name[ name_index ] );
	//	}
	//}
	//{
	//	int depart_index, name_index;
	//	for(depart_index=0;depart_index<3;depart_index++){\
	//		printf("%s \n", table[depart_index][0] );
	//		for(name_index=0;name_index<4;name_index++){
	//			printf("	%s ", table[name_index][1] );
	//		}
	//		printf("\n");
	//	}

	//}


/*	{
		printf("DepartName : %s \n", DepartName[0]);
		printf("	%s ", Name[0] );
		printf("	%s ", Name[1] );
		printf("\n");

		printf("DepartName : %s \n", DepartName[1]);
		printf("	%s ", Name[2] );
		printf("\n");

		printf("DepartName : %s \n", DepartName[2]);
		printf("	%s ", Name[3] );
		printf("\n");

	}*/

	return 0;
}

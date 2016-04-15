//#include <stdio.h>
//#include <String.h>
//#include <stdlib.h>
//
//int main(void) 
//{
//	char *departname [] = { "a team", "b team", "c team"};
//	char *name[] = { "kim", "jang", "dk" ,"phuc"};
//
//	
//
//	//char key[80] = {0};
//
//	int table[100][2];
//
//	int seq  = 0;
//
//	table[seq++][0] = 0;
//	table[seq++][1] =0;
//	++seq;
//
//	table[seq++][0] = 0;
//	table[seq++][1] =1;
//	++seq;
//
//	table[seq++][0] = 1;
//	table[seq++][1] =2;
//	++seq;
//
//	table[seq++][0] = 2;
//	table[seq++][1] =3;
//	++seq;
//
//	{
//		int i,j;
//		int departindex,nameindex;
//		for( i=0; i <3; ++i)
//		{
//			printf("depart name: %s \n" , departname[i]);
//			for(j =0; j<seq; ++j)
//			{
//				departindex = table[j][0];
//				if(i == departindex)
//				{
//					nameindex = table[j][1];
//					printf(" %s", name[nameindex]);
//				}
//				
//			}printf("\n");
//		}
//	}
//	return 0;
//}
//	
//‪#‎include‬ <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//	// struct _person
//	// {
//	// int seq;
//	// char *name;
//	// };
//	// 
//	// int view(struct _person param)//4 bytes
//	// {
//	// // because struct variable size is big
//	// //address only 4 (32 bits) 8(64bits) bytes
//	// 
//	// 
//	// }
//	// struct _relation_index
//	// {
//	// int depart_code;
//	// int person_number;
//	// };
//	int main(void)
//{
//	char *DepartName[] = {"A team","B team","C team"};
//	char *Name[] = {"Kim","Jang","ok","Phuc"};
//	char key[80]={0};
//	int table[100][2]; // [0] depart is index [1] name is index
//	// must be great than numbers of person
//	int seq =0;
//	table[seq][0]=0;
//	table[seq][1]=0;
//	++seq;
//	table[seq][0]=0;
//	table[seq][1]=1;
//	++seq;
//	table[seq][0]=1;
//	table[seq][1]=2;
//	++seq;
//	table[seq][0]=2;
//	table[seq][1]=3;
//	++seq;
//	{
//		int i;
//		int depart_name,name_index;
//		for (i=0;i<seq;++i)
//		{
//			depart_name = table[i][0];
//			printf("%s \n",DepartName[depart_name]);
//			name_index = table[i][1];
//			printf("%s \n",Name[name_index]);
//		}
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _person 
{
	int seq; 
	char name[40];
}person;

typedef struct _depart {
	int code; 
	char name[40];
	person member[20];
}depart;

typedef struct _info{
	int seq;
	char name[40];
}T;
T Teams[10];
T member[20];

depart departs[10];

//Binary I/O is struct in C, class C++

typedef struct _content
{
	int seq;
	char *title;
	int date_sec;
	int user_seq;
	int read_count;
}T;



int search(void)
{

	return 0;
}
int main(void)
{
	Teams[0].seq =1;
	strcpy(Teams[0].name , "Mobile Dev");
	

	Teams[1].seq =2;
	strcpy(Teams[1].name , "Web Dev");

	member[0].seq =1;	
	strcpy(member[0].name , "James Down");

	//depart type is one variable all data already merge

	departs[0].code =1;
	strcpy(departs[0].name , "Game Dev");
	departs[0].member[0].seq =10;
	strcpy(departs[0].member[0].name , "James Down");


	return 0;
}

//int main(void) 
//	{
//		char *departname [] = { "a team", "b team", "c team"};
//		char *name[] = { "kim", "jang", "dk" ,"phuc"};
//	
//		
//	
//		char key[80] = {0};
//		int table[3][3]={0};
//		int seq  = 0;
//	    
//		table[0][0] = 0;
//		table[0][1] =1;
//		table[1][0] =2;
//		table[2][1] =3;
//	
//		{
//			int i,j;
//			int departindex,nameindex;
//			for( i=0; i <3; ++i)
//			{
//				printf("depart name: %s \n" , departname[i]);
//				for(j =0; j<3; ++j)
//				{
//					nameindex = table[i][j];
//					//departindex = table[i][j];
//						printf(" %s", name[nameindex]);
//				}printf("\n");
//			}
//		}
//		return 0;
//	}
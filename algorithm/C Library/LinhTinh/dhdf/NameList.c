#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef	struct _node{
	int	seq;	// number of node(name)
	char	*name;	// dynamic allocate
	struct _node	*link;
}NODE, *PNODE;

int	displayNameList(PNODE	nameList[], int size );
int AddName(PNODE	*pTail, const char *name);
/*
	NameList's index number means alpabet
	- 0 means 'a'
	- 1 means 'b' .... 
	-25 means 'z'
*/
int main( void ){
	PNODE	NameList[28]={0};// save string about friends name
	int i;
	int idx;
	char	buffer[80]={0};
	int select;//menu number

	while( 1 ){
		system("cls");
		displayNameList( NameList , 26 );
		printf("Input new name : ");
		gets( buffer );
		idx = buffer[0]-'a';// idx's range must be from 0 to 25
		if( 0 <= idx && idx <= 25 ){
			AddName( NameList+idx, buffer );
		}

	}
	return 0;
}

int AddName(PNODE	*pTail, const char *name){
	PNODE	new_node;
	PNODE	tail;

	tail = *pTail;
	new_node = (PNODE)calloc(1,sizeof(NODE));
	new_node->name = (char*)calloc( strlen(name), sizeof(*name));
	strcpy( new_node->name, name);

	if( tail == NULL ){
		new_node->seq = 1;
	}else{
		new_node->seq = tail->seq + 1;
	}
/*	new_node->seq = 1;
	new_node->seq += (tail == NULL ) ? 0 : tail->seq ; 
	new_node->seq = (tail == NULL ) ? 1 : (tail->seq+1) ; */

	new_node->link = tail;
	tail = new_node;

	*pTail = tail;
	return 0;
}


int	displayNameList(PNODE	nameList[], int size ){
	int i;
	PNODE	tail;
	for(i=0;i<size;++i){
		tail = nameList[i];
		{
			PNODE	temp;
			temp = tail;
			while(temp){
				printf("[%2d]	%s\n", temp->seq, temp->name);
				temp = temp->link;
			}
		}
	}
	return 0;
}

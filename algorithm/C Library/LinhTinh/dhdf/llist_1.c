
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//for memset()

typedef	char	String[80];// use pointer better than array
typedef	String	DATA;

typedef	struct _node{
	DATA	title;//	array name is address
	struct _node *ptr;
}NODE;
typedef	NODE	*PNODE;

PNODE	NodeCreate(const char	*arg){
	//return value is address of NODE
	PNODE	new_node=NULL;
	new_node = malloc(1*sizeof(NODE));
	new_node->ptr = NULL;
	memset(new_node->title,0,sizeof(new_node->title) );
	// array's all elements is 0
	if( arg != NULL ){
		strcpy( new_node->title, arg );
	}
	return new_node;
}
//Read
//Update
//Delete
int main( void ){
	// very important that first node have NULL and
	//	last node have pre_node address at linked list
	PNODE	tail = NULL;// is last node's address
	char	Buffer[80]={0};
	int i;
	PNODE	temp;

	tail = NodeCreate("inserted string");
	for(i=0;i<5;++i){// add node
		sprintf(Buffer, "%d string data", i+1  );
		temp = NodeCreate(Buffer);
		temp->ptr = tail;
		tail = temp;
	}
	{//	all print
		PNODE	temp;
		temp = tail;
		while( temp ){//	NULL == (void*)0
			printf("%s\n", temp->title);
			temp = temp->ptr;// prev node's address
		}
	}
	{// delete node 
		PNODE	temp;
		char	srch_key[80]="5";
		PNODE	del_node;
		PNODE	prev_node;// ?
		temp = tail;
		while( temp ){
			if( strstr(temp->title, srch_key) ){
				// srch_key is sub string of title
				del_node = temp;
				break;
			}
			prev_node = temp;
			temp = temp->ptr;// move to prev node
		}
		if( temp != NULL ){
			// delete process
			if( del_node == tail ){
				tail = del_node->ptr;
			}else{
				prev_node->ptr = del_node->ptr;
			}
			free( del_node );
		}else{
			// fail searching
			printf("Not found delete position \n");
		}
	}
	{//	all print
		PNODE	temp;
		temp = tail;
		while( temp ){//	NULL == (void*)0
			printf("%s\n", temp->title);
			temp = temp->ptr;// prev node's address
		}
	}
	return 0;
}

int main_3( void ){
	PNODE	tail;// is last node's address
	char	Buffer[80]={0};
	int i;
	PNODE	temp;

	tail = NodeCreate("first string");
	for(i=0;i<5;++i){// add node
		sprintf(Buffer, "%d string data", i+1  );
		temp = NodeCreate(Buffer);
		temp->ptr = tail;
		tail = temp;
	}
	{//	all print
		PNODE	temp;
		temp = tail;
		while( temp ){//	NULL == (void*)0
			printf("%s\n", temp->title);
			temp = temp->ptr;// prev node's address
		}
	}
	{// insert node if you have to sorting , you need insert process
		PNODE	temp;
		char	srch_key[80]="6";
		PNODE	insert_node;
		insert_node = NodeCreate("inserted node data");
		temp = tail;
		while( temp ){
			if( strstr(temp->title, srch_key) ){
				// srch_key is sub string of title
				break;
			}
			temp = temp->ptr;// move to prev node
		}
		if( temp != NULL ){
			// insert process
			insert_node->ptr = temp->ptr;
			temp->ptr = insert_node;
		}else{
			// fail searching
			printf("Not found insert position \n");
			free( insert_node );
		}
	}
	{//	all print
		PNODE	temp;
		temp = tail;
		while( temp ){//	NULL == (void*)0
			printf("%s\n", temp->title);
			temp = temp->ptr;// prev node's address
		}
	}
	return 0;
}

int main_2( void ){
	PNODE	tail;// is last node's address
	tail = NodeCreate("first string");
	{// add node
		PNODE	temp;
		temp = NodeCreate("second string");
		temp->ptr = tail;
		tail = temp;
	}
	{// add node
		PNODE	temp;
		temp = NodeCreate("third string");
		temp->ptr = tail;
		tail = temp;
	}

	{//	all print
		PNODE	temp;
		temp = tail;
		while( temp ){//	NULL == (void*)0
			printf("%s\n", temp->title);
			temp = temp->ptr;// prev node's address
		}
	}

	return 0;
}

int main_1( void ){
	PNODE	tail;//or head
// to create new memory(node)	
	tail = NodeCreate("first string");
	if( tail == NULL ){	/* do not process	*/}
	puts("Your contents title : ");
	puts( tail->title );
	return 0;
}

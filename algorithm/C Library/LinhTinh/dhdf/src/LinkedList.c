#include "DnA.h"
// to easy coding, use global variables better than local
typedef	int	DATA;
struct	_node{
	DATA data;
	struct _node	*link;
};
typedef	struct _node	NODE;
typedef NODE	*PNODE;

/* Global Var.	*/
PNODE	gTail=NULL;

int	GetInteger(void){// cannot return (-) value
	int value=0;
	char c;
	while( (c=getchar()) != '\n' && (c>='0'&&c<='9')){
		value=value*10+(c-48);
	}
	return value;
}
PNODE	CreateNode(){
	PNODE	t;
	t = calloc(1, sizeof(NODE));
	return t;
}
// 1 function within 1 page (24 lines)
int AddNode(void){	// this function called "push" when use Stack
	int data;
	PNODE	new_node;
	printf("add data input : ");
	data = GetInteger();
	new_node = CreateNode();
	new_node->data = data;
	new_node->link = NULL;

	// add new node at tail of list
	new_node->link = gTail;
	gTail = new_node;
	return 0;
}
DeleteAll(){
	PNODE	del;// address of deleted node
	PNODE	temp;
	temp = gTail;
	while( temp ){
		del = temp;
		temp = temp->link;
		free(del);
	}
	gTail = NULL;

}
PrintAll(){
	PNODE	temp;
	temp = gTail;
	printf(":: Start List :: \n");
	while( temp ){
		printf("%d \n", temp->data );
		temp = temp->link;
	}
	printf(":: END List :: \n");
}
PNODE	SearchNode(){
	PNODE	srched_node = NULL;
	PNODE	temp;
	DATA	key;

	printf("input your search value : ");
	key = GetInteger();

	temp = gTail;
	while(temp){
		if( temp->data == key ){
			srched_node = temp;
			break;
		}
		temp = temp->link;
	}
	return srched_node;
}
int	InsertNode(){
	PNODE	prev_node;
	PNODE	new_node;
	// searching node where you want to insert
	prev_node = SearchNode();
	// to create new node
	if( prev_node == NULL ){	return EOF;	}

	new_node = CreateNode();
	printf("input insert value : ");
	new_node->data = GetInteger();
	new_node->link = NULL;
	
	// to modify nodes link
	new_node->link = prev_node->link;
	prev_node->link = new_node;
	return 0;
}
int	DeleteNode(){
	PNODE	delete_node;
	PNODE	prev_node;
	PNODE	temp;
	// searching node that you want to delete
	delete_node = SearchNode();
	if( delete_node == NULL ){	return EOF;	}//	EOF is -1

	// to modify nodes link
	if( delete_node == gTail ){
		gTail = gTail->link;
	}else{
		temp = gTail;
		while( temp ){
			if( temp->link == delete_node ){
				prev_node = temp;
				break;
			}
			temp = temp->link;
		}
		prev_node->link = delete_node->link;
	}
	// delete node
	free(delete_node);
	return 0;	// 0 means process success
}

int main(void){
	int	select;
	PNODE	rs=NULL;
	while(1){
		system("cls");
		PrintAll();
		printf(	"[1]Add [2]SearchEquals "
				"[3]All Delete [4]Delete "
				"[5]Insert "
				"[0]Exit\n"
		);
		printf("Select menu : ");
		select = GetInteger();
		if( select==0 ){	break;	}
		switch( select ){
			case 1:
				printf("Add processing.....\n");
				AddNode();
				break;// must write
			case 2:
				printf("Searching .........\n");
				rs = SearchNode();// only 1
				if( rs == NULL ){
					printf("Fail searching \n");
				}else{
					printf("%d in %p \n", rs->data, &rs->data );
					system("pause");
				}
				break;
			case 3:
				DeleteAll();
				printf("deleted all datas \n");
				break;
			case 4:
				DeleteNode();
				break;
			case 5:
				InsertNode();
				break;
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef	struct _node{
	int data;
	struct _node *link;
}NODE, *PNODE;

PNODE	MakeNode(int data){
	PNODE	node;
	node = (PNODE)malloc(sizeof(NODE));
	node->data = data;
	node->link = NULL;
	return node;
}
PNODE	SearchMinNode(PNODE	tail, int data){
	PNODE	result=NULL;
	PNODE	temp;
	temp = tail;
	while( temp && temp->data > data){
		result = temp;
		temp = temp->link;
	}
	return result;
}
PNODE	SearchMaxNode(PNODE	tail, int data){
	PNODE	result=NULL;
	PNODE	temp;
	temp = tail;
	while( temp && temp->data < data){
		result = temp;
		temp = temp->link;
	}
	return result;
}
PNODE	SearchPreNode(PNODE	tail, int data){
	PNODE	result=NULL;
	PNODE	temp;

	if(tail && tail->data == data )	return tail;
	temp = tail;	
	while( temp && temp->data != data){
		result = temp;
		temp = temp->link;
	}
	if(temp==NULL)	result = NULL;
	return result;
}
PNODE	InsertNode(PNODE	tail){
	int data;
	PNODE	node, cur, pre;

	printf("Input data : ");
	scanf("%d", &data);	fflush(stdin);
	node = MakeNode(data);
	pre = SearchMinNode(tail, data);
	if(pre==NULL){
		node->link = tail;
		tail = node;
	}else{
		if( pre->link != NULL )	node->link = pre->link;
		pre->link = node;
	}
	return tail;
}
PNODE	DeleteNode(PNODE	tail){
	int data;
	PNODE	node, cur, pre;

	if( tail ){
		printf("Delete data : ");
		scanf("%d", &data);	fflush(stdin);
		pre = SearchPreNode(tail, data);
		if(pre != NULL){
			if( pre==tail){
				node = pre;
				tail = pre->link;
			}else{
				node = pre->link;
				pre->link = NULL;
				if( node->link != NULL )
					pre->link = node->link;
			}
			free(node);
		}
	}
	return tail;
}
int	Free(NODE	*p){
	if( p ){
		Free(p->link);
		free(p);
	}
	return 0;
}
int	ShowList(PNODE	temp){
	while( temp ){
		printf("%d \n", temp->data );
		temp = temp->link;
	}
	return 0;
}
int main(void){
	PNODE	tail = NULL;
	PNODE	temp;
	int		menu;
	while(1){
		system("cls");
		ShowList(tail);
		printf("[1]Insert [2]Delete [0]Exit \n");
		scanf("%d", &menu);
		if( menu == 0 )	break;
		if( menu == 1 ){
			tail = InsertNode(tail);
		}
		if( menu == 2 ){
			tail = DeleteNode(tail);
		}
		system("pause");
	}
	Free(tail);
	return 0;
}
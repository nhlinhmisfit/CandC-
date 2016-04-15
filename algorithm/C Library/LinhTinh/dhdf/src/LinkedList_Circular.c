
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef	int DATA;

struct _node{
	DATA	value;
	struct	_node	*link;
};
typedef struct _node	NODE;
typedef NODE	*PNODE;

int	printMessage(const char *msg){
	puts(msg);
	getch();
	return 0;
}

int llist_main(void){
	PNODE	head= NULL;
	PNODE	tail= NULL;
	PNODE	ptemp= NULL;
	PNODE	new_node;
	DATA	arg;
	int list_count = 0;

	if( head ){
		ptemp = head;
		while( ptemp->link != head ){	list_count++;	}
		tail = ptemp;
		printf("tail of List : %p\nElements : %d \n", tail, list_count);
	}else{
		printMessage("List is Empty");
	}

	printMessage("Add element ");
	arg= rand();
	new_node = (PNODE)malloc( sizeof(NODE) );
	if( new_node == NULL ){	printMessage("Malloc Error");	return 0;	}
	new_node->value = arg;
	new_node->link = NULL;
	if( !head )	{
		head = new_node;
		head->link = head;
	}else{
		ptemp = head;
		while( ptemp->link != head ){	list_count++;	ptemp = ptemp->link; }
		ptemp->link = new_node;
	}

	printMessage("List 출력 합니다");
	if( head ){
		ptemp = head;
		do{
			list_count++;
			printf("List's Element value: %d \n", ptemp->value);
			ptemp = ptemp->link;
		}while( ptemp != head );
	}else{
		printMessage("List is Empty");
	}


	return 0;
}
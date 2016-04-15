
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _node{
	int v;
	struct _node *link;
};
struct _node *tail;
int main( void ){
	struct _node * head=NULL;
	struct _node * tail=NULL;
	struct _node * node;

	while(getch()!='\r'){
		node = (struct _node *)malloc( sizeof(*node) );
		node->v = rand();
		if( head == NULL ){
			head = tail = node;
		}else{
			tail->link = node;
			tail = node;
		}
	}


	node = head;
	while(node){
		printf("%d	\n", node->v );
		node = node->link;
	}
	return 0;
}

int main_20( void ){
	int	list[10];
	int *p;
	int i = 1;
	p = list;//[0]
	while( p != (list+10) ){
		*p = i++;
		p++;
	}

	p = list+9;
	while( p != (list-1) ){
		printf("%d \n", *p--);
	}

	return 0;
}
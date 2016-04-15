
#include "DnA.h"

LQUEUE	dataQ;
typedef	int	DATA;

int	initQueue(LQUEUE	*q){
	q->front = q->rear = NULL;
	return 0;
}
int isEmpty(LQUEUE	*q){
	if( q->front == NULL ){
		return 1;
	}
	return 0;
}
int	enQueue(LQUEUE	*q, DATA	v){
	LLIST	*newnode;

	newnode = (LLIST*)malloc( sizeof(LLIST) );
	newnode->link = NULL;
	newnode->data = New(DATA);
	*(DATA*)newnode->data = v;

	if( isEmpty(q) ){
		q->front = q->rear = newnode;
	}else{
		q->rear->link = newnode;
		q->rear = newnode;
	}
	return 0;
}
DATA deQueue(LQUEUE *q){
	LLIST	*del;
	DATA	rt;
	if( isEmpty(q) ){
		printf("Queue Empty \n");
		return EOF;
	}
	del = q->front;
	rt = *(DATA*)del->data;
	q->front = q->front->link;
	free(del->data);
	free(del);
	return rt;
}
int main(void){

	initQueue(&dataQ);
	enQueue(&dataQ, 10);
	enQueue(&dataQ, 20);
	enQueue(&dataQ, 30);
	enQueue(&dataQ, 40);
	enQueue(&dataQ, 50);
	while( !isEmpty(&dataQ)  ){
		printf("%d \n",	deQueue(&dataQ)	);
	}


	return 0;
}
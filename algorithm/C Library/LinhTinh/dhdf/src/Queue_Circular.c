
#include "DnA.h"

CQUEUE	dataQ;
typedef	int	DATA;

int	initQueue(CQUEUE	*q){
	q->front = 0;
	q->rear = 0;
	return 0;
}
int isEmpty(CQUEUE	*q){
	if( q->front == q->rear ){
		return 1;
	}
	return 0;
}
int	NextIndexOf(int idx){
	if( idx == QSIZE-1 ){
		return 0;
	}
	return idx+1;
}
int	enQueue(CQUEUE	*q, DATA	v){
	
	if( NextIndexOf(q->rear) == q->front ){
		printf("Queue Full \n");
		return EOF;
	}
	q->rear = NextIndexOf(q->rear);
	q->_Array[q->rear] = v;

	return 0;
}
DATA deQueue(CQUEUE *q){
	DATA	rt;
	if( isEmpty(q) ){
		printf("Queue Empty \n");
		return EOF;
	}
	q->front = NextIndexOf(q->front);
	rt = q->_Array[q->front];
	return rt;
}
int main(void){
	int i;
	initQueue(&dataQ);
	for(i=0;i<30;i++){
		enQueue(&dataQ, i+1);
	}
	while( !isEmpty(&dataQ)  ){
		printf("%d \n",	deQueue(&dataQ)	);
	}


	return 0;
}
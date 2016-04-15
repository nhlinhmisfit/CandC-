#include "src/DnA.h"

// please print what element have 1 every rows
int		ar[10][10]={
	{1,0,0,0,0,1,0,0,0,0}
	{0,0,0,0,1,0,1,0,0,0}
};
int	search_value(  ){

	search_value();
	return 0;
}
int main( void ){

	return 0;
}
/*
struct _node{
	int value;
	struct _node	*link;
};
typedef	struct _node	NODE;

NODE	*search_node(NODE *p,int key){
	if(p==NULL){
		return NULL;
	}	
	if(p->value == key ){
		return p;
	}
	return	search_node(p->link,key);
}
int main( void ){
	NODE	a={0};
	NODE	b={0};
	NODE	c={0};
	NODE	*rs;

	a.value = 10;
	a.link = &b;
	b.value = 20;
	b.link = &c;
	c.value = 30;
	c.link = NULL;
	rs = search_node( &a, 20 );
	printf("%d \n", rs->value);
*
	{
		NODE	*temp;
		temp = &a;
		while( temp ){
			if( temp->value == 20 ){
			}
			temp = temp->link;
		}
	}
/

	return 0;
}
*/
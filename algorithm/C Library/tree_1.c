
#include <stdio.h>
#include <stdlib.h>

typedef	int	DATA;
typedef	struct _node{
	DATA	v;
	struct _node	*left_link;
	struct _node	*right_link;
}NODE, *PNODE;

PNODE	CreateNode(DATA *param){
	PNODE	temp;
	temp = (PNODE)malloc( sizeof(NODE) );
	if( param == NULL ){ 
		temp->v = 0;	
	}else	{
		temp->v = *param;	
	}
	temp->left_link = NULL;
	temp->right_link = NULL;

	return temp;
}
int	AddNode(PNODE	root, DATA arg){
	PNODE	new_node;
	new_node = (PNODE)malloc( sizeof(NODE) );
	new_node->left_link = NULL;
	new_node->right_link = NULL;
	new_node->v = arg;

	if( root ){
		// to do
	}else{
		// to do
	}

	/* to do */

	return 0;
}
int	PrintAll(PNODE	root){
	// to do
	return 0;
}
int	MakingTree(DATA p[], int size, PNODE *root){
	PNODE	temp;
	int i;
	for(i=0;i<size;++i){
		AddNode(root, p[i]);
	}
	return 0;
}
int main( void ){
	DATA	unsorted[20];
	int i;
	for(i=0;i<20;++i)	unsorted[i] = rand()%1000+1;
	for(i=0;i<20;++i)	printf("%d ",unsorted[i]);	printf("\n");

	{
		PNODE	root = NULL;
		MakingTree(unsorted, 20, &root);
		PrintAll(root);
	}
	return 0;
}

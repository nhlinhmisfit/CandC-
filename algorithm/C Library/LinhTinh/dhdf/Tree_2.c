
#include <stdio.h>
#include <stdlib.h>

typedef	int	DATA;
typedef	struct _node{
	DATA	v;
	struct _node	*left_link;
	struct _node	*right_link;
}NODE, *PNODE;

DATA	get_data( void ){
	DATA t = EOF;	// -1
	printf("Integer : ");
	scanf("%d", &t);
	return t;
}
int		set_data(PNODE	p,DATA	param){
	p->v = param;
	return 0;
}
PNODE	CreateNode(DATA *param){
	PNODE	temp;
//	temp = (PNODE)calloc( 1, sizeof(NODE) );
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
int	UpdateNode(PNODE	dest, NODE	arg){
	if( dest != NULL ){
		*dest = arg;
	}
	return 0;
}
int	PrintNode(NODE param){
	printf("%d	%p	%p\n", 
		param.v, param.left_link, param.right_link);
	return 0;
}
/*
int	AddNode(PNODE	root, PNODE arg){
	if(root->left_link == NULL){
		root->left_link = arg;
		return 1;
	}
	AddNode(root->left_link, arg);
	return 0;
}
int	PrintAll(PNODE	root){
	PNODE	temp;
	temp = root;
	while(temp){
		printf("%d	%p\n", temp->v, temp->left_link);
		temp = temp->left_link;
	}

	return 0;
}
*/
int	AddNode(PNODE	root, PNODE arg){
	if(root->left_link == NULL){
		root->left_link = arg;
		return 1;
	}
	if(root->right_link == NULL){
		root->right_link = arg;
		return 2;
	}
	AddNode(root->left_link, arg);
	return 0;
}
int	PrintAll(PNODE	root){
	if(root == NULL ){
		return 1;
	}
	printf("%d	", root->v);
	PrintAll(root->left_link);
	PrintAll(root->right_link);
	return 0;
}

int main( void ){
	PNODE	root = NULL;
	PNODE	new_node;
	int seq = 0;

	for(seq=1;seq<6;++seq){
		new_node = CreateNode(&seq);
		if( root == NULL )	root = new_node;
		else{
			AddNode(root, new_node);
		}
	}
	PrintAll(root);
	return 0;
}

		// move to level's parent
		// node counting or save node's address
		//	select linked list or array
		//	access type Stack, Queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct _node{
	int	value;
	struct _node *left, *right;
}T, *PT;

PT	makingSample( void ){
	PT	root;
	PT	temp;
	int	value;

	root = (PT)calloc( 1,sizeof(T) );
	root->value = 1;

	temp = (PT)calloc( 1,sizeof(T) );
	temp->value = 2;

	root->left = temp;

	temp = (PT)calloc( 1,sizeof(T) );
	temp->value = 3;

	root->right = temp;

	temp = (PT)calloc( 1,sizeof(T) );
	temp->value = 4;

	root->left->left = temp;

	temp = (PT)calloc( 1,sizeof(T) );
	temp->value = 5;

	root->left->right = temp;

	temp = (PT)calloc( 1,sizeof(T) );
	temp->value = 6;

	root->right->left = temp;
	return root;
}
int PrintPreOrder(PT root){
	if( root == NULL ) return 1;
	printf("%d	", root->value);
	PrintPreOrder(root->left);
	PrintPreOrder(root->right);
	return 0;
}
int PrintInOrder(PT root){
	if( root == NULL ) return 1;
	PrintInOrder(root->left);
	printf("%d	", root->value);
	PrintInOrder(root->right);
	return 0;
}
int PrintPostOrder(PT root){
	if( root == NULL ) return 1;
	PrintPostOrder(root->left);
	PrintPostOrder(root->right);
	printf("%d	", root->value);
	return 0;
}
int main( void ){
	PT	main_root = NULL;
	int	count;
	main_root = makingSample();
	printf("PreOrder\n\t");
	PrintPreOrder(main_root);printf("\n");
	printf("InOrder\n\t");
	PrintInOrder(main_root);printf("\n");
	printf("PostOrder\n\t");
	PrintPostOrder(main_root);printf("\n");

	return 0;
}

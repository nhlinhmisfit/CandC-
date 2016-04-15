//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef	int	DATA;
//typedef	struct _node{
//	DATA	v;
//	struct _node	*left_link;
//	struct _node	*right_link;
//}NODE, *PNODE;
//
//PNODE	CreateNode(DATA *param){
//	PNODE	temp;
//	temp = (PNODE)malloc( sizeof(NODE) );
//	if( param == NULL ){ 
//		temp->v = 0;	
//	}else	{
//		temp->v = *param;	
//	}
//	temp->left_link = NULL;
//	temp->right_link = NULL;
//
//	return temp;
//}
//int	AddNode(PNODE	root, DATA arg){
//	PNODE	new_node;
//	new_node = (PNODE)malloc( sizeof(NODE) );
//	new_node->left_link = NULL;
//	new_node->right_link = NULL;
//	new_node->v = arg;
//
//	if( root ){
//		if( root->left_link == NULL ){
//			root->left_link = new_node;
//		}else if( root->right_link == NULL ){
//			root->right_link = new_node;
//		}else{
//			free(new_node);
//			AddNode(root->left_link, arg);
//		}
//	}
//
//	return 0;
//}
//int AddNode1(PNODE root, DATA arg)
//{
//	PNODE newnode;
//	newnode = (PNODE) malloc(sizeof(NODE));
//	newnode ->left_link = NULL;
//	newnode ->right_link = NULL;
//	newnode ->v= arg;
//
//
//	return 0;
//}
//int	PrintAll(PNODE	node){
//	if(node == NULL )	return 1;
//	PrintAll(node->left_link);
//	printf("%d	\n", node->v );
//	PrintAll(node->right_link);
//	return 0;
//}
//int	MakingTree(DATA p[], int size, PNODE *root){
//	PNODE	temp;
//	int i=0;
//	if( p == NULL || size <= 0){
//		return 1;
//	}
//	if( *root == NULL ){
//		*root = (PNODE)malloc( sizeof(NODE) );
//		(*root)->left_link = NULL;
//		(*root)->right_link = NULL;
//		(*root)->v = p[i++];
//	}
//	for(;i<size;++i){
//		AddNode(*root, p[i]);
//	}
//	//	*root = address of tree root node
//	return 0;
//}
//int main( void ){
//	DATA	unsorted[20];
//	int i;
//	for(i=0;i<20;++i)	unsorted[i] = rand()%1000+1;
//	for(i=0;i<20;++i)	printf("%d ",unsorted[i]);	printf("\n");
//
//	{
//		PNODE	root = NULL;
//		//		root = MakingTree(unsorted, 20, root);
//		MakingTree(unsorted, 20, &root);
//		PrintAll(root);
//	}
//	return 0;
//}

//
//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <memory.h>
//struct _node{
//	int data;
//	struct _node	*left, *right;
//};
//typedef struct _node	BTree;
//typedef BTree	*PBTree;
//
//int GenTree(PBTree parent) {
//	static int value = 1;
//	if(parent == NULL ) return 1; 
//	parent->left = (PBTree)calloc(1,sizeof(BTree));
//	parent->left->data = value++;
//	parent->right = (PBTree)calloc(1,sizeof(BTree));
//	parent->right->data = value++;
//	return 0;
//}
//int Print(PBTree root){
//	if(root == NULL ) return 1;
//
//	printf("%d	", root->data );
//	Print(root->left);
//	Print(root->right);
//	return 0;
//}
//int main( void ){
//	PBTree	root;
//	PBTree list[100]={0};
//	PBTree list_sub[100]={0};
//	int i,j,level=1;
//	root = (PBTree)calloc(1,sizeof(BTree) );
//	root->data = 0;
//	list[0] = root;
//	for(level=1;level<100;++level){
//		for(i=0,j=0;list[i];++i){
//			GenTree( list[i] );	// create child (left, right);
//			list_sub[j++] = list[i]->left;
//			list_sub[j++] = list[i]->right;
//		}
//		/*	memset(list,0,sizeof(list));
//		for(i=0;i<j;++i){
//		list[i] = list_sub[i];
//		}*/
//		size=i ;
//		list = list_sub;
//		list_sub =NULL;
//	}	
//
//	Print(root);
//	return 0;
//}
//int traverse_main( void ){
//	PBTree root;
//	PBTree parent;
//	root = (PBTree)malloc( sizeof( BTree ) );
//	root->data = 0;
//	root->left = root->right = NULL;
//
//	parent = root;
//	while(getch()!='\r'){
//		GenTree(parent);
//		if( parent->left->left == NULL ){
//			parent = parent->left;
//		}else if( parent->right->left == NULL ){
//			parent = parent->right;
//		}else{
//
//		}
//	}
///*
//	parent = root->left;
//	GenTree(parent);
//	parent = root->right;
//	GenTree(parent);
//*/
//	Print(root);
//
//
//	return 0;
//}
//
//printf("");
//
//
//
//
//
//
//


#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct _node{
	int data;
	struct _node	*left, *right;
};
typedef struct _node	BTree;
typedef BTree	*PBTree;

PBTree	Root;	// init NULL

int main(void){
// yes->left, no->right select yes or no
	int selected;
	int value = 1;
	PBTree	new_node, temp;

	Root = (PBTree)malloc( sizeof(BTree) );
	Root->data = value++;
	Root->left = Root->right = NULL;
	temp = Root;
	while(1){
		printf("[1]Yes [2]No \n");
		scanf("%d", &selected);	fflush(stdin);
		if( selected == 1 ){
			new_node = (PBTree)malloc( sizeof(BTree) );
			new_node->data = value++;
			new_node->left = new_node->right = NULL;
			temp->left = new_node;
			temp = temp->left;
		}
		if( selected == 2 ){
			new_node = (PBTree)malloc( sizeof(BTree) );
			new_node->data = value++;
			new_node->left = new_node->right = NULL;
			temp->right = new_node;
			temp = temp->right;
		}
	}

	return 0;
}


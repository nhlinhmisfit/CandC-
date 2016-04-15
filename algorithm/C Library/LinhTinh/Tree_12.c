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
typedef struct _llist{
	PT	node;
	struct _llist	*link;
}LLIST;

PT	makingSample( void );
int Print(PT list[], int size );

// Why not use Array?
int main( void ){
	int	list[5000]={0};
	int *p = malloc( sizeof(int) * 400 * 300 );

	return 0;
}

int main_30( void ){
	PT	main_root = NULL;
	LLIST *head=NULL;
	LLIST *temp;
	main_root = makingSample();

	temp = (LLIST*)malloc( sizeof(LLIST) );
	temp->node = main_root->left;	// level 1's node
	temp->link = head;
	head = temp;

	temp = (LLIST*)malloc( sizeof(LLIST) );
	temp->node = main_root->right;	// level 1's node
	temp->link = head;
	head = temp;



	return 0;
}
int main_12( void ){
	PT	main_root = NULL;
	PT	node;
	PT	list[20]={NULL};
	int	value;
	int level;
	int size;
	main_root = makingSample();
	for(level=0;level<4;++level){
		size = 0;
		printf("Level %d \n", level);
		{// what to do
		}
		Print(list,size);
	}

	level = 0;
	size = 0;
	printf("Level %d \n", level);
	list[size++] = main_root;
	Print(list,size);

	level = 1;	// is child of Level 0
	size = 0;
	printf("Level %d \n", level);
	list[size++] = main_root->left;
	list[size++] = main_root->right;
	Print(list,size);

	level = 2;	// is child of Level 1
	size = 0;
	printf("Level %d \n", level);
	node = main_root->left;
	list[size++] = node->left;
	list[size++] = node->right;
	node = main_root->right;
	list[size++] = node->left;
	list[size++] = node->right;
	Print(list,size);


	level = 3;	// is child of Level 2
	size = 0;
	printf("Level %d \n", level);
	node = main_root->left->left;
	list[size++] = node->left;
	list[size++] = node->right;

	node = main_root->left->right;
	list[size++] = node->left;
	list[size++] = node->right;

	node = main_root->right->left;
	list[size++] = node->left;
	list[size++] = node->right;

	node = main_root->right->right;
	list[size++] = node->left;
	list[size++] = node->right;
	Print(list, size);

	return 0;
}
int Print(PT list[], int size ){
	int i;
	PT node;
	for(i=0;i<size;++i){
		node = list[i];
		if( node != NULL )	printf("%d	", node->value);
	}
	printf("\n");
	return 0;
}

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

	temp = (PT)calloc( 1,sizeof(T) );
	temp->value = 7;

	root->right->right = temp;

	temp = (PT)calloc( 1,sizeof(T) );
	temp->value = 8;

	root->left->left->left = temp;
	return root;
}

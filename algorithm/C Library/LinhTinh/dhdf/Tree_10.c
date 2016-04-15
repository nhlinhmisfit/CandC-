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

	temp = (PT)calloc( 1,sizeof(T) );
	temp->value = 7;

	root->right->right = temp;
	return root;
}
int CountNode(PT node){
	int count = 0;
	if( node == NULL )	return 0;
	if( node->left != NULL ) ++count;
	if( node->right != NULL ) ++count;
	count = CountNode(node->left) + CountNode(node->right);
	return count+1;
}
int main( void ){
	PT	main_root = NULL;
	int	count;

	main_root = makingSample();
	count = CountNode(main_root);// max : 4
	printf("Level[%d]'s node : %d\n", -1, count);

	{
		PT	level_zero[10]={NULL};
		PT	level_one[10]={NULL};
		PT	level_two[4]={NULL};

		level_zero[0] = main_root;
		level_one[0] = level_zero[0]->left;
		level_one[1] = level_zero[0]->right;
		level_two[0] = level_one[0]->left;
		level_two[1] = level_one[0]->right;
		level_two[2] = level_one[1]->left;
		level_two[3] = level_one[1]->right;

		{
			int level_no;
			int i;
			int size;
			PT	*base;
			level_no = 2;
			switch(level_no){
				case 0:	base = level_zero;	break;
				case 1:	base = level_one;	break;
				case 2:	base = level_two;	break;
			}
			for(i=0;base[i];++i){
				printf("%d	", base[i]->value );// *(base+i)
			}
			printf("\n");
		}
	}

	return 0;
}
	//// pa save level 2's node addr	
	//count_level = 0;
	//temp = main_root->left->left;
	//pa[count_level++] = temp;
	//temp = main_root->left->right;
	//pa[count_level++] = temp;
	//temp = main_root->right->left;
	//pa[count_level++] = temp;
	//temp = main_root->right->right;
	//pa[count_level++] = temp;
	//printf("Level[%d]'s node : %d\n", 2, count_level);

	//count = 0;
	//count_level = 0;
	//count += CountNode(pa[count_level++]);
	//count += CountNode(pa[count_level++]);
	//count += CountNode(pa[count_level++]);
	//count += CountNode(pa[count_level++]);
	//printf("Level[%d]'s node : %d\n", 1, count);

/*
int	CountNode(PT parent){
	int count=0;
	if( parent->left != NULL )	++count;
	if( parent->right != NULL)	++count;
	return count;
}
int	CountNodeLevel(PT root, int level_no){
	int	count = 0;
	if( level_no == 0 )	count = 1;
	else{
		count += CountNode(root->left);
		count += CountNode(root->right);
	}
	return count;
}
*/

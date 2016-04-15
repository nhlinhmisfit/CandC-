//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct _node
//{
//	int value;
//	struct _node *left, *right;
// }T, *PT;
//PT makingSample(void)
//{
//	PT root;
//	PT temp;
//	int value;
//
//	root = (PT)calloc(1,sizeof(T));
//	root->value =1;
//
//	temp = (PT)calloc(1,sizeof(T));
//	temp-> value=2;
//	root ->left = temp;
//
//	temp = (PT)calloc(1,sizeof(T));
//	temp ->value =3;
//	root ->right = temp;
//
//	temp = (PT)calloc(1,sizeof(T));
//	temp ->value =4;
//	root ->left->left = temp;
//
//	temp = (PT)calloc(1,sizeof(T));
//	temp ->value =5;
//	root ->left->right = temp;
//
//	temp = (PT)calloc(1,sizeof(T));
//	temp ->value =6;
//	root ->right->left = temp;
//
//	return root;
//}
//int countnode1(PT parent)
//{
//	int count =0; 
//	if(parent ->left != NULL) count++;
//	if(parent ->right != NULL) count++;
//	return count;
//}
//int countNodelevel(PT root, int levelno)
//{
//	int count =0;
//	if(levelno == 0)
//		count = 1;
//	else
//	{
//		//move to level's parent
//		// node counting or save node's address
//		//select linked list or array
//		// acess type stack or queue
//
//
//		count += countnode1(root->left);
//		count += countnode1(root->right);
//
//	}
//	return count;
//}
//int countnode(PT node)
//{
//	int count =0;
//	if(node ==NULL) 
//		return 0;
//	if(node ->right !=NULL) ++count;
//	if(node ->left !=NULL) ++count;
//
//	count = countnode(node->left) + countnode(node->right);
//	return count+1;
//}
//int main(void)
//{
//	PT mainroot = NULL;
//	int count;
//	mainroot = makingSample();
//
//	//count = countNodelevel(mainroot,2);
//	count = countnode(mainroot);
//	printf("level [%d]'s node: %d\n", 0, count);
//
//	{
//		PT level_zero[10];
//		level_zero[0] = mainroot;
//		PT level_one[10];
//
//		level_one[0] = level_zero[0]->left;
//		level_one[1] = level_zero[0]->right;
//		PT level_two[4];
//
//		level_two[0] = level_one[0]->left->left;
//		level_two[1] = level_one[0]->left->right;
//		level_two[2] =level_one[1]->right->left;
//		level_two[3] = level_one[1]->right->right;
//
//		{
//			int levelno;
//			int i;
//			for(i = 0; i<; ++i)
//			{
//				printf("%d", );
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
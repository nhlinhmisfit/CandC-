//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct _object{
//	int	type;	//1:team, 2:team member
//	char	name[80];
//}DTO;
//typedef	DTO	DATA;
//typedef	struct _node{
//	DATA	v;
//	struct _node	*left_link;
//	struct _node	*right_link;
//}NODE, *PNODE;
//
//PNODE	CreateNode(DATA param){
//	PNODE	temp;
//	temp = (PNODE)malloc( sizeof(NODE) );
//	temp->v = param;	
//	temp->left_link = NULL;
//	temp->right_link = NULL;
//	return temp;
//}
//
//int	AddNode2Left(PNODE	parent, DATA arg){
//	PNODE	new_node;
//	new_node = (PNODE)malloc( sizeof(NODE) );
//	new_node->left_link = NULL;
//	new_node->right_link = NULL;
//	new_node->v = arg;
//
//	parent->left_link = new_node;
//
//	return 0;
//}
//
//int	AddNode2Right(PNODE	parent, DATA arg){
//	PNODE	new_node;
//	new_node = (PNODE)malloc( sizeof(NODE) );
//	new_node->left_link = NULL;
//	new_node->right_link = NULL;
//	new_node->v = arg;
//
//	parent->right_link = new_node;
//
//	return 0;
//}
//
//int	PrintTeamName(PNODE	node){
//	if(node == NULL )
//		return 1;
//	printf("%s	\n", node->v.name );
//	PrintTeamName(node->left_link);
//	return 0;
//}
//int	PrintMemberName(PNODE	node){
//	if(node == NULL )	
//		return 1;
//	printf("%s	\n", node->v.name );
//	PrintMemberName(node->right_link);
//	return 0;
//}
//int	PrintAllName(PNODE	node){
//	if(node == NULL )
//		return 1;
//	printf("%s	", node->v.name );
//	PrintAllName(node->left_link);
//	printf("[ ");
//	PrintAllName(node->right_link);
//
//	printf("]\n");
//	return 0;
//}
//int	AddNode(PNODE	root, DATA arg)
//{
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
//	return 0;
//}
//int main( void ){
//	PNODE	root = NULL;
//	PNODE	team = NULL;
//	DATA	sample[]={
//		{1,"GlobePoint"},{1,"Vietnam"},{1,"Mobile Dev"},{1,"Web Dev"},
//		{2,"Van"},{2, "Quang"},{2, "Hieu"},{2, "The"},{2, "Linh1"},{2, "Linh2"}
//	};
//	root = (PNODE)malloc( sizeof(NODE) );
//	root->left_link = root->right_link = NULL;
//	root->v = sample[0];
//
//	/*AddNode2Left(root, sample[1]);
//	AddNode2Left(root->left_link, sample[ 2 ]);
//	AddNode2Left(root->left_link->left_link, sample[ 3 ]);
//	AddNode2Right(root->left_link->left_link ,sample[8]);*/
//	{
//		DATA temp;
//		while(1)
//		{
//			system("cls");
//			printf("type: ");
//			if(!scanf("%d", &temp.type) || (temp.type != 1 && temp.type !=2)) break;
//
//			fflush(stdin);
//			printf("Name: ");
//			gets(temp.name);
//			/*if(temp.type ==1 )
//			{
//			AddNode2Left(root,temp);
//			}
//			else
//			{
//			AddNode2Right(root,temp);
//			}*/
//			AddNode(root,temp);
//
//		}
//	}
//	PrintAllName(root);
//	PrintTeamName(root);
//	PrintMemberName(root);
//	//PrintMemberName(root->left_link->left_link);
//	return 0;
//}

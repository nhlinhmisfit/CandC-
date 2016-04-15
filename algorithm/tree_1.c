
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _object{
	int	type;	//1:team, 2:team member
	char	name[80];
}DTO;
typedef	DTO	DATA;
typedef	struct _node{
	DATA	v;
	struct _node	*left_link;
	struct _node	*right_link;
}NODE, *PNODE;

PNODE	CreateNode(DATA param){
	PNODE	temp;
	temp = (PNODE)malloc( sizeof(NODE) );
	temp->v = param;	
	temp->left_link = NULL;
	temp->right_link = NULL;
	return temp;
}
int	AddNode2Left(PNODE	parent, DATA arg){
	PNODE	new_node;
	if(parent->left_link == NULL){
		new_node = (PNODE)malloc( sizeof(NODE) );
		new_node->left_link = NULL;
		new_node->right_link = NULL;
		new_node->v = arg;
		parent->left_link = new_node;
	}else{
		AddNode2Left(parent->left_link, arg);
	}
	return 0;
}
int	AddNode2Right(PNODE	parent, DATA arg){
	PNODE	new_node;
	if(parent->right_link == NULL){
		new_node = (PNODE)malloc( sizeof(NODE) );
		new_node->left_link = NULL;
		new_node->right_link = NULL;
		new_node->v = arg;
		parent->right_link = new_node;
	}else{
		AddNode2Right(parent->right_link, arg);
	}
	return 0;
}
int	PrintTeamName(PNODE	node){
	if(node == NULL )	return 1;
	printf("%s	\n", node->v.name );
	PrintTeamName(node->left_link);
	return 0;
}
int	PrintMemberName(PNODE	node){
	if(node == NULL )	return 1;
	printf("%s	\n", node->v.name );
	PrintMemberName(node->right_link);
	return 0;
}
int	PrintAllName(PNODE	node){
	if(node == NULL )	return 1;
	printf("[ %s ]\n\t", node->v.name );
	if(node->left_link){
		printf("	left[%s]	", node->left_link->v.name );
	}
	if(node->right_link){
		printf("right[%s]", node->right_link->v.name );
	}
	printf("\n");
	PrintAllName(node->left_link);
	PrintAllName(node->right_link);
	printf("");
	return 0;
}
PNODE	FindAddressNode(PNODE root, const char *name){
	PNODE	addr = NULL;
	if( root ){
		if(strcmp(root->v.name,name)==0){
			return root;
		}
		addr = FindAddressNode(root->left_link, name);
	}
	return addr;
}
int	AddNode(PNODE root, DATA arg){
	PNODE	team_node;
	char	key[80];
	switch(arg.type){
	case 1:
		AddNode2Left(root,arg);	
		break;
	case 2:
		PrintTeamName(root);
		printf("Input team name : ");
		gets( key );
		team_node = FindAddressNode( root, key );
		if( team_node ){
			AddNode2Right(team_node,arg);
		}else{	printf("Not found team %s \n", key);	}
		break;
	}
	return 0;
}
int main( void ){
	PNODE	root = NULL;
	PNODE	team = NULL;
	DATA	sample[]={
		{1,"GlobePoint"},{1,"Vietnam"},{1,"Mobile Dev"},{1,"Web Dev"},
		{2,"Van"},{2,"Quang"},{2,"Hieu"},{2,"The"},{2,"Linh"},{2,"Linh"}
	};
	root = (PNODE)malloc( sizeof(NODE) );
	root->left_link = root->right_link = NULL;
	root->v = sample[0];

	{
		DATA	temp;
		while(1){
			printf("Type : ");
			if(!scanf("%d", &temp.type) || temp.type==-1 )break;	
			fflush(stdin);
			printf("Name : ");
			gets( temp.name );
			/* Add node process here */
			AddNode(root,temp);
		}
	}
	PrintAllName(root);
	PrintTeamName(root);
	PrintMemberName(root);
	return 0;
}
//AddNode2Left(root, sample[1]);
//AddNode2Left(root->left_link, sample[ 2 ]);
//AddNode2Left(root->left_link->left_link, sample[ 3 ]);
//
//AddNode2Right(root->left_link->left_link ,sample[8]);

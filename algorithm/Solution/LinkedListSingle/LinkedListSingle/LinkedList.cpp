//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////typedef char String[80];  // CRUD
//typedef int DATA;
//
//typedef struct _NODE {
//	DATA data;
//	struct _NODE *Link;
//
//};
//
//typedef struct _NODE NODE;
//typedef NODE *PNODE;
//
//PNODE gTail = NULL;
//
//int GetInteger(void) //cannot return (-) value
//{
//	int value =0;
//	char c;
//	while((c= getchar())!= '\n' && ( c>= '0' && c<='9'))
//	{
//		value = value*10 +( c -48);
//	}
//	return value;
//}
//
//
//PNODE CreatNode()
//{
//	PNODE t; 
//	t = (PNODE)calloc(1,sizeof(NODE));
//	return t;
//}
//
//
//int AddNode(void)
//{
//	int data; 
//	PNODE NewNode;
//
//	printf("Insert data: ");
//	data = GetInteger();
//
//	NewNode = CreatNode();
//
//	NewNode ->data =data;
//	NewNode ->Link = NULL;
//	
//	NewNode ->Link = gTail;
//	gTail = NewNode;
//
//	return 0;
//}
//
//PNODE SearchNode()
//{
//	PNODE srchednode = NULL;
//	PNODE temp;
//
//	DATA key;
//	printf("input your search: ");
//	key = GetInteger();
//
//	temp = gTail;
//	while(temp){
//		if(temp -> data == key)
//		{
//			srchednode = temp;
//			break;
//		}
//		temp = temp -> Link;
//
//	}
//	return srchednode;
//}
//int InsertNode(void)
//{
//	PNODE prev,newnode;
//	prev = SearchNode();
//
//	if (prev == NULL){ return EOF; }
//	newnode = CreatNode();
//	printf("input insert data: ");
//	newnode ->data = GetInteger();
//	newnode->Link == NULL;
//	
//	//modify linked
//	newnode ->Link = prev->Link;
//	prev ->Link = newnode;
////	newnode->Link = prev;
//
//	return 0;
//
//}
////my function
////int InsertNode(void)
////{
////	PNODE temp;
////	PNODE nodeinsert;
////	PNODE rs;
////	int data;
////	printf("Insert data: ");
////	data = GetInteger();
////
////	nodeinsert = CreatNode();
////	nodeinsert->data =data;
////	rs = SearchNode();
////	temp = gTail;
////	
////	while(temp)
////	{
////		if(rs == NULL)
////		{
////			break;
////		}
////		temp = temp ->Link;
////	}
////	if(temp !=NULL)
////	{
////		nodeinsert ->Link =temp ->Link;
////		temp ->Link = nodeinsert;
////	}
////	else 
////	{
////		printf("fail insert");
////		free(nodeinsert);
////	}
////	return 0;
////}
//int DeleteAll(void)
//{
//	PNODE del;//address of delete node
//	PNODE temp;
//
//	temp = gTail;
//	while(temp)
//	{
//		del = temp;		
//		temp = temp ->Link;
//		free(del);
//	}
//	gTail = NULL;
//	return 0;
//}
//int DeleteNode(void)
//{
//	PNODE del,temp,prev;
//
//	//prev = SearchNode();
//	del = SearchNode();
//	if(del ==NULL)
//	{
//		return EOF; //EOF is -1
//	}
//	if(del ==gTail)
//	{
//		gTail = gTail ->Link;
//	}
//	else
//	{
//		temp = gTail;
//		while(temp)
//		{
//			if(temp -> Link == del)
//			{
//				prev = temp;
//				break;
//			}
//			temp = temp -> Link;
//		}
//		prev ->Link = del ->Link;
//	}
//	free(del);
//	return 0;
//}
//void PrintAll()
//{
//	printf(":: Start List ::\n");
//	PNODE temp;
//	temp = gTail;
//	while(temp)
//	{
//		printf("%d\n",temp ->data);
//		temp = temp -> Link;
//	}
//	printf(":: End List ::\n");
//}
//int main(void)
//{
//	int select;
//	PNODE rs;
//	while(1)
//	{
//		system("cls");
//		PrintAll();
//		printf("[1]Add [2] SearchEquals [3] DeleteAll [4] InsertNode [5] DeleteNode[0]Exit\n");
//		printf("Select menu: ");
//		select = GetInteger();
//		if(select == 0 ){ break;}
//		
//		switch(select)
//		{
//		case 1:
//			{
//				printf("Add processing....\n");
//				AddNode();
//				break;
//			}
//			
//		case 2:
//			printf("Searching ..............\n");
//			rs = SearchNode();
//			if(rs == NULL)
//			{
//				printf("Fail searching\n");
//				system("pause");
//			}
//			else
//			{
//				printf("%d in %p\n", rs ->data,&rs ->data );
//				system("pause");
//			}
//			break;
//		case 3:
//			DeleteAll();
//			printf("delete all datas\n");
//			system("pause");
//			break;
//		case 4: 
//			InsertNode();
//
//			break;
//		case 5: 
//			DeleteNode();
//			break;
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
//
//
//typedef int DATA;
//struct _node{
//	DATA data;
//	struct _node *link;
//};
//typedef struct _node NODE;
//typedef NODE *PNODE;
///*Global Variable*/
//PNODE gTail;
//PNODE CreateNode()
//{
//	PNODE t;// allocate memory
//	t = (PNODE)malloc(1*sizeof(NODE));
//	return t;
//}
//int AddNode(void)
//{
//	PNODE new_node;
//	int data;
//	printf("Add Data Input : ");
//	scanf("%d",&data);
//	new_node = CreateNode();
//	//insert process
//	new_node->data=data;
//	new_node->link=NULL;
//	//add new node at tail of list
//	//linking process
//	new_node->link = gTail;
//	gTail= new_node;
//	return 0;
//}
//int InsertNode(void)
//{
//	PNODE insert_node;
//	int data;
//
//	return 0;
//}
//int DeleteNode(void)
//{
//	return 0;
//}
//int DeleteAll(void)
//{
//	return 0;
//}
//void PrinAll()
//{
//	PNODE temp;
//	temp = gTail;
//	printf("------ Start List -------\n");
//	while(temp)
//	{
//		printf("\t\t %d \n",temp->data);
//		temp = temp->link;
//	}
//	printf("------  End List  -------\n");
//
//}
////PNODE FindNode()
////{
////
////}
//void main()
//{
//	int iChoice=1;
//	while(iChoice!=0)
//	{
//		//system("cls");
//		printf("1.Add Node\n");
//		printf("2.Insert Node\n");
//		printf("3.Delete Node\n");
//		printf("4.Delete All\n");
//		printf("5.Print All\n");
//		printf("6.Find Node\n");
//		printf("0.Exit\n");
//		scanf("%d",&iChoice);
//		fflush(stdin);
//		/*	if(iChoice==0){break;}*/
//		switch(iChoice)
//		{
//		case 0:
//
//			break;
//		case 1:
//			printf("Adding Process..............\n");
//			AddNode();
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4:
//			break;
//		case 5:
//			PrinAll();
//			break;
//		case 6: 
//			break;
//
//
//		}
//
//	}
//
//}
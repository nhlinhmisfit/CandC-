//#include<stdio.h>
//#include <string.h>
//#include <windows.h>
//#include <time.h>
//
//typedef struct _NODE {
//	int seq;
//	char *name; // dynamic allocate
//	struct _NODE *Link;
//}NODE,*PNODE;
//// NAMELIST's index  number means alphabet
//// -0 means 'a'
//// .... -> 25 means 'z'
//
//
//int displayNameList(PNODE nameList[], int size);
//int AddName(PNODE *pTail, const char * name);
//int main(void)
//{
//	NODE *NameList[28] = {0}; // save string about friends name
//
//	int i; 
//	int idx;
//	char buffer[80]={0};
//	int select; 
//	while(1)
//	{
//		system("cls");
//		displayNameList(NameList, 26);
//		printf("Input new name: ");
//		gets(buffer);
//
//		idx = buffer[0] - 'a'; // idx's range must be from 0 to 25
//		if(0 <= idx && idx <=25)
//		{
//			AddName(NameList + idx,buffer);
//		}
//	}
//
//	return 0;
//}
//int displayNameList(PNODE nameList[], int size)
//{
//	int i;
//	PNODE tail;
//
//	for( i =0 ; i<size ; ++i)
//	{
//		tail = nameList[i];
//		{
//			PNODE temp;
//			temp =tail;
//			while(temp)
//			{
//				printf("[%2d] %s\n", temp ->seq);
//				temp = temp -> Link;
//			}
//		}
//	}
//	return 0;
//}
//int AddName(PNODE *pTail, const char * name)
//{
//	PNODE newnode;
//	PNODE tail;
//	tail = *pTail;
//
//	newnode= (PNODE) calloc(1, sizeof(NODE));
//	newnode -> name = (char *) calloc(strlen(name), sizeof(*name));
//	strcpy(newnode ->name, name);
//
//	if(tail == NULL)
//	{
//		newnode -> seq =1;
//	}
//	else 
//	{
//		newnode -> seq = (*pTail) ->seq + 1;
//	}
//	//newnode ->seq =1;
//	//newnode ->seq += ( tail ==NULL) ? : tail ->seq;
//
//	newnode -> Link = tail;
//
//	//(*pTail) = newnode;
//	tail = newnode;
//
//	*pTail = tail;
//
//	return 0;
//}
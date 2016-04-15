//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef char String[80]; //dung contro tot hon array
//typedef String DATA;
//
//typedef struct _NODE {
//	//String title; //arr name is address
//	DATA title;
//	struct _NODE *ptr;
//
//}NODE;
//
//typedef NODE *PNODE;
//
//PNODE NodeCreate(const char *arg )
//{
//	//return value is address of NODE
//	PNODE new_node = NULL;
//	new_node = (PNODE)malloc(sizeof(NODE)*1);// 1 *  sizeof(NODE) = sizeof(NODE) *1
//	new_node -> ptr = NULL;
//	memset(new_node ->title, 0 , sizeof(new_node->title));
//	//if(arg ==NULL){
//	//	new_node ->title[0] = 0;
//	//}
//	//else
//	//{
//	//	strcpy(new_node ->title, arg);
//	//}
//	if(arg !=NULL)
//	{
//		strcpy(new_node ->title, arg);
//	}
//	//if calloc's return NULL
////	memset(new_node,0,sizeof(NODE));// if you call malloc, realloc 
//	/*if(new_node == NULL)
//	{
//	printf("Memory allocate fail\n");
//	}*/
//	return new_node;
//}
//
//int main(void)
//{
//	PNODE tail;
//	char Buffer[80]= {0};
//	int i ;
//	PNODE temp;  
//	tail = NodeCreate("firt string");
//	for( i = 0 ; i < 5; ++i)
//	{//add nodes
//		sprintf(Buffer,"%d string data ",i +1);
//		temp = NodeCreate(Buffer);
//		temp -> ptr  = tail;
//		tail = temp;
//	}
//	//{//add nodes
//	//	PNODE temp;  
//	//	temp = NodeCreate("third string");
//	//	temp -> ptr  = tail;
//	//	tail = temp;
//	//}
//
//	{
//		PNODE temp;
//		temp =tail;
//		printf("\n");
//		while(temp)
//		{
//			printf("%s \n", temp->title);
//			temp = temp -> ptr; //pre node's add
//		}
//	}
//
//	{//insert node 
//		PNODE temp;
//		char srch_key[80]="3"; 

//		PNODE insert_node;
//		insert_node = NodeCreate("inset node");
//		temp = tail;
//		while(temp)
//		{
//			if( strstr(temp ->title, srch_key))
//			{ //srch key is sub string of title
//				break;
//			}
//			
//			temp = temp -> ptr; //move to pre node
//		}
//		if(temp != NULL)
//		{
//			//intert node 
//			insert_node ->ptr = temp->ptr;
//			temp->ptr = insert_node;
//		}
//		else
//		{
//			printf("fail found inset position");
//			free (insert_node);
//		}
//	}
//	{//all print
//		PNODE temp;
//		temp = tail;
//		printf("\n");
//		while(temp)
//		{
//			//NULL == (void*)0;
//			printf("%s\n",temp->title);
//			temp = temp->ptr;//previous node's address
//		}
//	}
//	{
//		//Delete Node
//		PNODE temp;
//		char srch_key[80]="inset node";//search key =3
//		PNODE delete_node;
//		PNODE prev_node;
//		temp =tail; 
//		while(temp)
//		{
//			if(strstr(temp->title,srch_key))
//			{
//				//srch_key is sub string of title
//				delete_node = temp;
//				break;
//			}
//			prev_node =temp;
//			temp = temp->ptr;//move to prev node
//		}
//		if(temp!=NULL)
//		{
//			//delete process
//			if(delete_node == tail)
//			{
//				tail = delete_node->ptr;
//			} 
//			else
//			{
//				prev_node->ptr=delete_node->ptr; free(delete_node);
//			}
//			
//		}
//		else
//		{
//			// fall searching
//			printf("Not Found delete position\n");
//		}
//	}
//	{//all print
//		PNODE temp;
//		temp = tail;
//		printf("\n");
//		while(temp)
//		{
//			//NULL == (void*)0;
//			printf("%s\n",temp->title);
//			temp = temp->ptr;//previous node's address
//		}
//	}
//	return 0;
//}
//int main_1(void) 
//{
//	PNODE tail; //or head
//	tail = NodeCreate("firt string");
//
//	if(tail ==NULL)
//	{
//
//	}
//	puts("you contents title: ");
//	//gets(tail->title);
//	puts( tail->title);
//	return 0;
//}
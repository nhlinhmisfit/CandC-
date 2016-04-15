//#include <stdio.h>
//#include <conio.h>
//#include <malloc.h>
//#include <string.h>
//#include <windows.h>
//
//
//typedef struct _AUTHOR
//{
//	int countAuthor;
//	char *author[5];
//}Author;
//typedef struct _ContentList
//{
//	int countContent;
//	char *content[10];
//}Contenlist;
//typedef struct _BOOK
//{
//	char *b_ISBNCode;
//	char *b_Title;
//	Author BookAuthor;
//	char *b_Publisher;
//	char *b_Price;
//	Contenlist ContentList;
//
//}BOOK;
//
//int check_input(char *input)
//{
//	if(*input==NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//void InputString(const char *pTitle,char **ppName)
//{
//	char temp[1024];
//	printf("%s: ",pTitle);
//	gets(temp);
//	*ppName=  (char *)malloc(strlen(temp)+1);
//	strcpy(*ppName,temp);
//}
//void InputAuthor(Author *pAuthor)
//{
//	pAuthor->countAuthor=0;
//	for(int i = 0; i < 5 ;i++){
//		printf("Author No %d",i+1);
//		InputString(" ",&(pAuthor->author[i]));
//		pAuthor->countAuthor++;
//		if(strcmp((pAuthor->author[i]),"")==0){
//			break;
//		}
//	}
//}
//void InputContenList(Contenlist *pContent)
//{
//	pContent->countContent=0;
//	for(int i=0;i<10;++i)
//	{
//		printf("Content No %d",i+1);
//		InputString(" ",&(pContent->content[i]));
//		pContent->countContent++;
//		if(strcmp((pContent->content[i]),"")==0){
//			break;
//		}
//	}
//}
//void InsertBookData(BOOK *pBook)
//{
//	InputString("ISBNCode",&pBook->b_ISBNCode);
//	InputString("Title",&pBook->b_Title);
//	InputAuthor(&pBook->BookAuthor); //
//	InputString("Publisher",&pBook->b_Publisher);
//	InputString("Price",&pBook->b_Price);
//	InputContenList(&pBook->ContentList);
//}
//void InsertBook(BOOK eBook[],int *piIndex,int iArraySize)
//{
//	if(*piIndex >= iArraySize)
//	{
//		printf("Can't Add New Member, Buffer is full\n");
//		return;
//	}
//	InsertBookData(&eBook[*piIndex]);
//	++(*piIndex);
//}
//void PrintAuthor(Author *pAuthor)
//{
//	printf("Number of Author : %d\n",pAuthor->countAuthor-1);
//	for(int i=0;i<5;++i)
//	{		
//		if(strcmp(pAuthor->author[i],"")==0)
//		{	break;	}
//		else
//		{	printf("Author No %d : %s \n",i+1,pAuthor->author[i]);}
//	}
//}
//void PrintContent(Contenlist *pContent)
//{
//	printf("Number of Content : %d\n",pContent->countContent-1);
//	for(int i=0;i<10;++i)
//	{
//		if(strcmp(pContent->content[i],"")==0)
//		{	break;	}
//		else
//		{	printf("Content No %d : %s \n",i+1,pContent->content[i]);}
//	}
//}
//void printBookData(BOOK *pBook)
//{
//	printf("ISBNCode    : %s\n",pBook->b_ISBNCode);
//	printf("Title       : %s\n",pBook->b_Title);
//	PrintAuthor(&pBook->BookAuthor);
//	printf("Price       : %s\n",pBook->b_Price);
//	PrintContent(&pBook->ContentList);
//	
//}
//void PrintAllBook(BOOK ArrayBook[],int *pIndex)
//{
//	for(int i=0;i< *pIndex;++i)
//	{
//		/*printf("ISBNCode    : %s\n",ArrayBook[i].b_ISBNCode);
//		printf("Title       : %s\n",ArrayBook[i].b_Title);
//		PrintAuthor(&ArrayBook[i].BookAuthor);
//		printf("Price       : %s\n",ArrayBook[i].b_Price);
//		PrintContent(&ArrayBook[i].ContentList);*/
//		printBookData(&ArrayBook[i]);
//		printf("\n");
//	}
//}
//int SearchBookDataByISBN(BOOK ArrayBook[],int iIndex,char *input)
//{
//	for(int i=0;i<iIndex;++i)
//	{
//		if(strcmp(ArrayBook[i].b_ISBNCode,input)==0)
//		{
//			return i;
//		}
//
//	}
//	return -1;
//}
//void SearchISBN(BOOK BookArray[],int iIndex)
//{
//	char input[1024];
//	printf("Search ISBN Code : ");
//	gets(input);
//	int iSearch= SearchBookDataByISBN(BookArray,iIndex,input);
//	if(iSearch!=-1){
//		printBookData(&BookArray[iSearch]);
//	}else
//	{
//		printf("Not Found");
//
//	}
//
//}
//void FreeArray(char **pointer)
//{
//	if(pointer) {
//		free(*pointer);
//		*pointer = NULL;
//	}
//	
//	
//}
//void FreeContent(Contenlist *pContent)
//{
//	for(int i=0;i<10;++i)
//	{
//		free(pContent->content[i]);
//	}
//}
//void FreeBookData(BOOK *pBook)
//{
//	free(pBook->b_ISBNCode);
//	free(pBook->b_Title);
//	FreeArray(pBook->BookAuthor.author);
//	free(pBook->b_Publisher);
//	free(pBook->b_Price);
//	FreeArray(pBook->ContentList.content);
//}
//
//void ModifyBook(BOOK BookArray[],int iIndex)
//{
//	char input[1024];
//	printf("ISBN Code : ");
//	gets(input);
//	int iSearch= SearchBookDataByISBN(BookArray,iIndex,input);
//	if(iSearch!=-1)
//	{ 
//		FreeBookData(&BookArray[iSearch]);
//
//		InsertBookData(&BookArray[iSearch]);
//	}else
//	{
//		printf("Not Found");
//
//	}
//}
//void SearchBookByAuthor(BOOK ArrayBook[],int *iIndex)
//{
//	char input[1024];
//	printf("Input author name :");
//	gets(input);
//	for(int i=0;i<*iIndex;++i)
//	{
//		for(int j=0;j<ArrayBook[i].BookAuthor.countAuthor;++j)
//		{
//			if(strcmp(input,ArrayBook[i].BookAuthor.author[j])==0)
//			{
//				printBookData(&ArrayBook[i]);
//				printf("\n");
//			}
//		}
//	}
//
//}
//void MultiSearchBookContentData(BOOK BookArray[],int iIndex, char *Name,int *iResultArray,int *piResultCount)
//{
//	*piResultCount=0;
//	for(int i=0;i<iIndex;++i)
//	{
//		for(int j=0;j<BookArray[i].ContentList.countContent;++j)
//		{
//			if(strstr(BookArray[i].ContentList.content[j],Name)!=NULL)
//			{
//				iResultArray[*piResultCount]=i;
//				++(*piResultCount);
//			}
//		}
//		
//	}
//}
//void MultiSearchBookAuthorData(BOOK BookArray[],int iIndex, char *Name,int *iResultArray,int *piResultCount)
//{
//	*piResultCount=0;
//	for(int i=0;i<iIndex;++i)
//	{
//		for(int j=0;j<BookArray[i].BookAuthor.countAuthor;++j)
//		{
//			if(strstr(BookArray[i].BookAuthor.author[j],Name)!=NULL)
//			{
//				iResultArray[*piResultCount]=i;
//				++(*piResultCount);
//			}
//		}
//
//	}
//}
//void PrintMultiSearchResult(BOOK BookArray[],int iResultArray[],int iResultCount)
//{
//	for(int i=0;i<iResultCount;++i)
//	{
//		printBookData(&BookArray[iResultArray[i]]);
//	}
//
//}
//void PrintMultiSearchAuthorResult(BOOK BookArray[],int iResultArray[],int iResultCount)
//{
//	for(int i=0;i<iResultCount;++i)
//	{
//		printBookData(&BookArray[iResultArray[i]]);
//	}
//
//}
//void MultipleSearchContent(BOOK BookArray[],int iIndex)
//	//can't use return, return just for one data
//{
//	char input[1024];
//	printf("Include Content String : ");
//	gets(input);
//	int * iResultArray = (int*)malloc(sizeof(int)*iIndex);
//	int iResultCount =0;
//	MultiSearchBookContentData(BookArray,iIndex,input,iResultArray,&iResultCount);
//	if(iResultCount==0){
//		printf("Not Found!");
//	}else
//	{
//		PrintMultiSearchResult(BookArray,iResultArray,iResultCount);
//		printf("\n");
//	}
//	free(iResultArray);
//
//}
//void MultipleSearchAuthor(BOOK BookArray[],int iIndex)
////	can't use return, return just for one data
//{
//	char input[1024];
//	printf("Include Author Name : ");
//	gets(input);
//	int * iResultArray = (int*)malloc(sizeof(int)*iIndex);
//	int iResultCount =0;
//	MultiSearchBookAuthorData(BookArray,iIndex,input,iResultArray,&iResultCount);
//	if(iResultCount==0){
//		printf("Not Found!");
//	}else
//	{
//		PrintMultiSearchResult(BookArray,iResultArray,iResultCount);
//		printf("\n");
//	}
//	free(iResultArray);
//
//}
///*Delete Area*/
//int DeleteAt(BOOK BookArray[],int * piIndex,int iSearch)
//{
//	if(*piIndex ==0 ||(iSearch<0 && iSearch<*piIndex))
//	{
//		return 0;
//	}
//
//	FreeBookData(&BookArray[iSearch]);
//	//MoveMemberData();
//	memcpy(&BookArray[iSearch],&BookArray[iSearch+1],sizeof(BOOK)*(*piIndex-iSearch-1));
//	--(*piIndex);
//	return 1;
//}
//void DeleteAllBook(BOOK BookArray[],int *piIndex)
//{
//	while(DeleteAt(BookArray,piIndex,*piIndex-1));
//}
//void DeleteMultiData(BOOK BookArray[],int iResultArray[],int iResultCount,int *piIndex)
//{
//	for(int i=iResultCount-1;i>=0;--i)
//	{
//		DeleteAt(BookArray,piIndex,iResultArray[i]);
//	}
//
//}
//void MultiDelete(BOOK BookArray[],int * piIndex)
//{
//	char Name[1024];
//	printf("Include Author name to delete book : ");
//	gets(Name);
//	int * iResultArray = (int*)malloc(sizeof(int)*(*piIndex));
//	int iResultCount =0;//Data Count
//	MultiSearchBookAuthorData(BookArray,*piIndex,Name,iResultArray,&iResultCount);
//	if(iResultCount==0){
//		printf("Not Found!");
//	}else
//	{
//		DeleteMultiData(BookArray,iResultArray,iResultCount,piIndex);
//	}
//	free(iResultArray);
//}
///*End Area*/
//	
//			
//
//
//void main()
//{
//	BOOK eBookArray[1024];
//	int iIndex =0;//NoData
//	int iChoice =1;
//	while(iChoice !=0)
//	{
//		system("CLS");
//		printf("------- Book Data ---------\n");
//		PrintAllBook(eBookArray,&iIndex);
//		printf("---------------------------\n");
//		printf("1.Insert Book\n");
//		printf("2.Print All Book\n");
//		printf("3.Search Book By ISBN\n");
//		printf("4.Modify by ISBN Code\n");
//		printf("5.Search By Author\n");
//		printf("6.Search Content\n");
//		printf("7.Delete All Book \n");
//		printf("8.Delete Book by Author Name\n");
//		scanf("%d",&iChoice);
//		fflush(stdin);
//		switch(iChoice)
//		{
//		case 1: 
//			InsertBook(eBookArray,&iIndex,sizeof(eBookArray)/sizeof(eBookArray[0]));
//			break;
//		case 2:
//			PrintAllBook(eBookArray,&iIndex);
//			system("pause");
//			break;
//		case 3:
//			SearchISBN(eBookArray,iIndex);
//			system("pause");
//			break;
//		case 4:
//			ModifyBook(eBookArray,iIndex);
//			system("pause");
//			break;
//		case 5:
//			MultipleSearchAuthor(eBookArray,iIndex);
//			system("pause");
//			break;
//		case 6:
//			MultipleSearchContent(eBookArray,iIndex);
//			system("pause");
//			break;
//		case 7:
//			DeleteAllBook(eBookArray,&iIndex);
//			break;
//		case 8:
//			MultiDelete(eBookArray,&iIndex);
//			break;
//		}
//	}
//
//}
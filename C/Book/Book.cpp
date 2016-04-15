#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct _Author
{
	char *Author[5] ;// array of pointer
}Author;

typedef struct _Content 
{
	char *Content[10];
}Content;
typedef struct _BOOK
{
	char * b_Isbncode;
	char * b_Title;
	char * b_Publisher;
	int  * b_Price;

	Author AuthorList;
	Content ContentList;

}BOOK;

void InputString(const char *pTitle, char **ppString)
{
	char temp[1024];
	printf("%s: ",pTitle);
	flushall();
	gets(temp);
	*ppString = (char *)malloc(strlen(temp)+1);
	strcpy(*ppString,temp);
}
void InputPrice(const char * pTitle, int **ppiPrice)
{
	int *temp;
	printf("%s: ", pTitle);
	scanf("%d", &temp);	
	fflush(stdin);
	*ppiPrice = (int *)malloc(sizeof(int*));
	*ppiPrice = temp;
}

void InputAuthor(Author *pAuthor,int *piIndex, int iAuthorArraySize)
{
	char *String;
	String = "\0" ;
	*piIndex = 0;
	while(*piIndex <5)
	{
		if(*piIndex >= iAuthorArraySize)
		{
			break;
		}
		else
		{
			InputString("Author ",&pAuthor->Author[*piIndex]);
			if(strcmp(pAuthor->Author[*piIndex], String) == 0)
				break;
		}
		++(*piIndex);
	}
}
void InputContent(Content *pContent, int *piIndex, int iContentArraySize)
{
	char *String;
	String = "\0" ;
	*piIndex = 0;
	while(*piIndex <10)
	{
		if(*piIndex >= iContentArraySize)
		{
			break;
		}
		else
		{
			InputString("Content ",&pContent->Content[*piIndex]);
			if(strcmp(pContent->Content[*piIndex], String) == 0)
				break;
		}
		++(*piIndex);
	}
}
void InputBookData(BOOK *pBook)
{
	int AuthorIndex ;
	int ContentIndex;
	InputString("ISBN code",&pBook->b_Isbncode);
	InputString("Title",&pBook->b_Title );
	InputString("Publisher",&pBook->b_Publisher );
	InputPrice("Price",&pBook->b_Price);
	InputAuthor(&pBook->AuthorList,&AuthorIndex,sizeof(pBook->AuthorList.Author)/sizeof(pBook->AuthorList.Author[0]));
	InputContent(&pBook->ContentList,&ContentIndex,sizeof(pBook->ContentList.Content)/sizeof(pBook->ContentList.Content[0]));
}
void InputBookMember(BOOK BookArray[], int *piIndex, int iArraySize)
{
	
	if(*piIndex >= iArraySize)
	{
		printf("can't add new member, buffer is full");
		return;
	}
	InputBookData(&BookArray[*piIndex]);
	++(*piIndex);
}
void PrintAuthor(Author *pAuthor)
{
	for(int i =0 ; i <5;++i)
	{
		if(strcmp(pAuthor->Author[i],"" )==0)
		{
			break;
		}
		else
		{
			printf("\tAuthor \" %s\"\n",pAuthor->Author[i]);
		}	
	}
}
void PrintContent(Content *pContent)
{
	for(int i =0 ; i <5;++i)
	{
		if(strcmp(pContent->Content[i],"" )==0)
		{
			break;
		}
		else
		{
			printf("\tContent \" %s\"\n",pContent->Content[i]);
		}	
	}
}
void PrintBookData(BOOK *pBook)
{
	printf("\tISBN Code: %s\n",pBook ->b_Isbncode);
	printf("\tTitle: %s\n",pBook->b_Title);
	printf("\tPublisher: %s\n",pBook ->b_Publisher);
	printf("\tPrice: %d\n",pBook ->b_Price);
	printf("\tLIST OF AUTHOR\n");
	PrintAuthor(&pBook->AuthorList);
	printf("\tCONTENT LIST\n");
	PrintContent(&pBook->ContentList);
}
void PrintAll(BOOK BookArray[],int iIndex)
{
	for(int i =0; i<iIndex; ++i)
	{
		printf("Book %d\n",iIndex);
		PrintBookData(&BookArray[i]);
	}
}

void main()
{
	BOOK BookArray[3];
	int iIndex =0;
	int iChoice = 1;
	while( iChoice !=0)
	{
		printf("\n1.Input\n");
		printf("2.Print All\n");
		printf("3.Search\n");
		scanf("%d", &iChoice);
		fflush(stdin);
		switch(iChoice)
		{
		case 1:
			InputBookMember(BookArray, &iIndex, sizeof(BookArray)/sizeof(BookArray[0]));
			break;
		case 2:
			PrintAll(BookArray,iIndex);
			break;
		}
	}
}


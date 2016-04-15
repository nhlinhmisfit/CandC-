#include< stdio.h>
#include < string.h>
#include <time.h>
#include <windows.h>
#include<stdlib.h>
#include <conio.h>

//pointer , dynamic array, allocation, linked list (single), stack queue use array
/*
	code , tiele, price, author
*/
struct _BOOK {
	unsigned int code;
	unsigned int price;
	char title[80];  // hoac char *title
	char author[80];
	int category_no;
};
typedef struct _BOOK BOOK;
typedef BOOK DATA;

struct _sLinkedList
{
	DATA *data;
	struct _sLinkedList *Link;
};
typedef struct _sLinkedList SLIST;

static SLIST BookList;
static char *CNames[] = {
	"Maniac", "animation","IT", "certification","MU"
};
char *getCategoryName(int no)
{
	
	if(!(1<=no && no <=5))
		no =0;
	return CNames[no];
}
int printcategory()
{
	int i;
	for(i =0; i <(sizeof(CNames)/sizeof(*CNames)); ++i)
	{
		printf("[%d]  %s\n", i, CNames[i]);
	}
	return 0;
}
int print_book (BOOK arg)
{
	printf("[%d] %s \n", arg.code, arg.title);
	printf("Author: %s\n", arg.author);
	printf("Price: %d\n",arg.price);
	printf("Category No.: %s\n",getCategoryName(arg.category_no));

	return 0;
}
int editbook(BOOK * param)
{
	char buffer[80]= {0};
	int input_price;
	int inputno;

	printf("Title: %s \n", param->title);
	buffer[0]= 0;
	gets(buffer);
	if(buffer[0] != '\0')
	{
		memset(param ->title,0,sizeof(param->title)); //80  // == buffer[0] = 0
		strcpy(param ->title, buffer);
	}
	printf("Author: %s >", param->author);
	buffer[0]= 0;
	gets(buffer);
	if(buffer[0] != '\0')
	{
		memset(param ->author,0,sizeof(80)); //80
		strcpy(param ->author, buffer);
	}

	printf("Price: %d\n",param->price);
	//gets(buffer);
	scanf(" %d", &param->price);
	fflush(stdin);

	printf("Category : %s\n",getCategoryName(param->category_no));
	printcategory();
	printf("select category no: ");
	scanf(" %d", &param -> category_no);
	fflush(stdin);

	return 0;
}
int inputbook(BOOK * param)
{
	unsigned int code =1;
	param ->code = code++;

	printf("Title: ");

	gets(param->title);


	printf("Author:" );
	gets(param->author);


	printf("Price: ");
	scanf(" %d", &param->price);
	fflush(stdin);

	printf("Category : ");
	printcategory();
	printf("select category no: ");
	scanf(" %d", &param -> category_no);
	fflush(stdin);

	return 0;
}
int print_book_list()
{
	DATA *pData;
	SLIST *pList;

	if(BookList.data &&	BookList.Link)
	{
		pList = &BookList;
		while(pList)
		{
			pData = pList ->data;
			printf("[%d]  %s \n",pData->code,pData->title);
			pList = pList->Link;
		}

	}
	else
	{
		printf("Book data is only 1 or Empty\n");
	}
	return 0;
}
int main(void)
{
	BOOK *temp;
	
	SLIST *node;
	print_book_list();
	
	for(int i =0; i<2; ++i)
	{
		temp = (BOOK *) calloc(1, sizeof(BOOK));
		inputbook(temp);
		if(BookList.data ==NULL)
		{
			BookList.data = temp;
		}
		else
		{
			node = (SLIST *)malloc(sizeof(SLIST));
			node ->data = temp;
			node -> Link = BookList.Link;
			BookList.Link = node;
		}
	}
	
	print_book_list();
	//print_book(*temp);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

/*	Book information
		Code, Title, Price, Author, Category
*/
struct _book{
	unsigned int code;
	unsigned int price;
	char	title[80];	// char *ptitle
	char	author[80];
	int		category_no;
};
typedef	struct _book	BOOK;

typedef BOOK	DATA;
struct _slinkedlist{
	DATA	*data;
	struct _slinkedlist	*link;
};
typedef struct _slinkedlist	SLIST;

static	SLIST	BookList;
static char	*CNames[] = {
	"Unselected","Maniacs","Animation","IT","Computer","Certification"
};
char *getCategoryName(int no){
	if( !(1<= no && no <=5) )	no = 0;// check boundary of array
	return CNames[no];
}
int	print_category_names(){
	int i;
	for(i=0;i<( sizeof(CNames)/sizeof(*CNames));++i){
		printf("[%d]	%s\n", i, CNames[i] );
	}
	return 0;
}
int print_book(BOOK arg){

	printf("[%d]	%s\n", arg.code, arg.title );
	printf("Author: %s \n", arg.author );
	printf("Price : %d \n", arg.price );
	printf("Category: %s \n", getCategoryName(arg.category_no) );
	return 0;
}
int edit_book(BOOK *param){
	// cannot edit book's code
	char	buffer[80] = {0};
	int		input_price;
	int		input_no;

	printf("Title: %s > ", param->title );
	buffer[0] = 0;
	gets( buffer );
	if( buffer[0] != '\0'){	// if inputed string
		memset(param->title,0,sizeof(param->title));
		strcpy(param->title, buffer);
	}
	printf("Author: %s > ", param->author );
	buffer[0] = 0;
	gets( buffer );
	if( buffer[0] != '\0'){	// if inputed string
		memset(param->author,0,sizeof(param->author));
		strcpy(param->author, buffer);
	}
	printf("Price : %d >", param->price );
	scanf("%d", &param->price ); fflush(stdin);

	printf("Category: %s \n", getCategoryName(param->category_no) );
	print_category_names();
	printf("select category no : ");
	scanf("%d", &param->category_no ); fflush(stdin);
	return 0;
}
int input_book(BOOK *param){
	static	unsigned int code = 1;

	param->code = code++;

	printf("Title: ");
	gets( param->title );

	printf("Author: " );
	gets( param->author );

	printf("Price : " );
	scanf("%d", &param->price ); fflush(stdin);

	printf("Category:" );
	print_category_names();
	printf("select category no : ");
	scanf("%d", &param->category_no ); fflush(stdin);
	return 0;
}
int	print_book_list(){
	DATA	*pData;
	SLIST	*pList;

	if( BookList.data && BookList.link ){
		pList = &BookList;
		while( pList ){
			pData = pList->data;
			printf("[%d]	%s\n",	pData->code,pData->title);
			pList = pList->link;
		}
	}else{
		printf("Book data is only 1 or Empty \n");
	}
	return 0;
}
int main( void ){
	BOOK	*temp;
	SLIST	*node;
	print_book_list();
	temp = (BOOK*)calloc(1,sizeof(BOOK));
	input_book( temp );
	if( BookList.data == NULL ){
		BookList.data = temp;
	}else{
		node = (SLIST*)malloc( sizeof(SLIST) );
		node->data = temp;		
		node->link = BookList.link;
		BookList.link = node;
	}
	print_book_list();
//	print_book(*temp);

	return 0;
}

#define	_DATA_TYPE_
#include "SRC\DnA.h"
typedef	struct _booktype{
	char	*title;
	int price;
	int qty;
}BOOK;
typedef	BOOK	DATA;
#define	FORMAT	"%s %d %d"
const char	*filename = "book.dat";

char *RandomString(int max);
int createSampleData(int sz);
int ready2test(void);

int main(void){
	ready2test();
	return 0;
}


char *RandomString(int max){
	char *temp;
	int i;
	temp = (char*)calloc(max+1,sizeof(char));
	for(i=0;i<max;i++){
		temp[i] = rand()%26+'a';
		if( temp[i]==0 )	break;
	}
	temp[0]-=32;
	return temp;
}
int createSampleData(int sz){
	FILE	*fp;
	int i;
	DATA	temp;
	char	writeBuffer[80];
	fp = fopen(filename, "w");
	for(i=0;i<sz;i++){
		temp.title = RandomString(10);
		temp.price = rand();
		temp.qty = rand();
		memset(writeBuffer,0,sizeof(writeBuffer));
		sprintf(writeBuffer, FORMAT"\n", temp.title, temp.price, temp.qty);
		fwrite(writeBuffer, sizeof(writeBuffer),1,fp);
	}
	fclose(fp);
	return 0;
}
int ready2test(void){
	srand((unsigned int)time(NULL));
	createSampleData(20);
	printf("테스트용 데이터가 %s 에 작성되었습니다.\n", filename);
	return 0;
}

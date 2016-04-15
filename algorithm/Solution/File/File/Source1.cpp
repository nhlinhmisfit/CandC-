#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char TagName[100][30];
int Row,Colum;
typedef struct _TagAndValue
{
	char tag[100];
	char value[1024];
}TV;

int TagRead(FILE *fp)
{
	int charac;
	charac = fgetc(fp);
	if(charac == '>')
	{
		return 0;
	}
	TagName[Row][Colum]= charac;
	++Colum;
	TagRead(fp);
	return 0;
}
int ReadValue(FILE *fp)
{
	int ch;
	ch = fgetc(fp);
	char Tag[100];

}
//int readline(FILE *fp)
//{
//	char *arrline[1024];
//
//	int linesize = 1024;
//	int i =0;
//	int c;
//	arrline[i] = (char *)malloc(linesize);
//	while (fgets(arrline[i],linesize, fp)) 
//	{
//		i++;
//		arrline[i] =(char *) malloc(linesize);
//	} 
//	int i1 =i;
//	for(int i = 0 ; i<i1 ; i++)
//	{
//		printf("%s ",arrline[i]);
//		free(arrline[i]);
//	}
//	return 1;
//}
int main(void)
{
	const char *fName= "DataFile.txt";
	FILE *fp;
	fp = fopen(fName,"r");
	if(fp ==NULL)
	{
		printf("Not found %s \n", fName);
		return EOF;  //-1
	}
	//int i = countline(fp);
	//printf("%d",i);
	fclose(fp);

	return 0;
}
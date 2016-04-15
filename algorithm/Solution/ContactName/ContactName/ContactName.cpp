#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
typedef struct _TELNO
{
	char * t_name;
	char * t_telno;
	
	//char * datetime;
}TELNO;

void InputString(const char *pTitle,char **ppString)
{
	char temp[1024];
	printf("%s: ",pTitle);
	flushall();
	gets(temp);
	*ppString = (char *)malloc(strlen(temp)+1);
	strcpy(*ppString,temp);
}
void InputTelnoDetail(TELNO *pTelNo)
{
	InputString("Name",&pTelNo->t_name);
	InputString("Number Phone",&pTelNo->t_telno);
}
void InputContact(TELNO ContactArray[], int *piIndex, int iArraySize)
{
	if(*piIndex	>=iArraySize)
	{
		printf("Can't add new member");
		return;
	}
	InputTelnoDetail(&ContactArray[*piIndex]);
	
	++(*piIndex);
}
void OutputTelnoDetail(TELNO *pTelNo)
{
	printf("Name: %s\n",pTelNo->t_name);
	printf("\t %s\n",pTelNo->t_telno);
}
void OutputContact(TELNO ContactArray[],int iIndex)
{
	for(int i =0;i <iIndex;++i)
	{
		OutputTelnoDetail(&ContactArray[i]);
	}
	getch();
}
//void FileSave(TELNO ContactArray[], int iIndex)
//{
//	FILE *fp;
//	fp = fopen("Contactbook.txt", "w");
//	if(fp == NULL)
//		printf("can't not open file\n");
//	else
//	{
//		for(int i =0 ; i< iIndex; ++i)
//		{
//			fprintf(fp, "%s - %s\n",ContactArray[i].t_name, ContactArray[i].t_telno);
//		}
//		fclose(fp);
//	}
//	printf("Already save...\n");
//	getch();
//}
//void ReadFile(TELNO ContactArray[],int iIndex)
//
//{
//	FILE *fp;
//	char c;
//	fp = fopen("Contactbook.txt", "r");
//	if(fp == NULL)
//		printf("can not open file\n");
//	else
//	{
//		
//			while((c = fgetc(fp))!= EOF)
//			{
//					printf("%c", c);
//			}		
//		fclose(fp);
//	}
//	getch();
//}
void InsertionSort(TELNO ContactArray[],int iIndex)
{
	int i, j;
	TELNO temp;
	for( i =0;i <iIndex; ++i)
	{
		temp = ContactArray[i];
		for(j = i-1; j>=0 && strcmp(temp.t_name, ContactArray[i].t_name)!=0; --j)
		{
			ContactArray[j+1] = ContactArray[j];

		}
		ContactArray[j+1] = temp;
	}
}
void main()
{
	TELNO ContactArray[10];
	int iIndex =0;
	int ichoice =1;
	while(ichoice !=0)
	{
		system("cls");
		printf("1.Input\n");
		printf("2.Output\n");
		//printf("3.Save File\n");
		//printf("4.Read File\n");
		scanf("%d", &ichoice);
		fflush(stdin);
		switch(ichoice)
		{
		case 1:
			InputContact(ContactArray,&iIndex,sizeof(ContactArray)/sizeof(ContactArray[0]));
			break;
		case 2:
			OutputContact(ContactArray,iIndex);
			break;
		case  3:
			//FileSave(ContactArray,iIndex);
			InsertionSort(ContactArray, iIndex);
			OutputContact(ContactArray,iIndex);
			break;
		case  4: 
			//ReadFile(ContactArray,iIndex);
			break;
		getch();

		}
	}
}


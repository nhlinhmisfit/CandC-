#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

void main()
{
	/*char name[12];
	char add[12];
	char phone[12];*/

	char temp[1024];
	char *pName1;
	char *pName2;

	printf("&temp -> %p\n",&temp);
	printf("&pName1 -> %p\n",&pName1);


	printf("Name1 : ");
	gets(temp);
	pName1 = (char *)malloc(strlen(temp)+1);
	strcpy (pName1, temp);
	printf("Name1 :%s\n",pName1);
	free(pName1);
	pName1 =NULL;

	printf("Name2 : ");
	gets(temp);
	pName2 = (char *)malloc(strlen(temp)+1);
	strcpy (pName2, temp);
	printf("Name2 :%s\n",pName2);
	free(pName2);
	pName2 =NULL;

	strcpy(pName1, "fdfdsf");
	printf("Name1 :%s\n",pName1);
	printf("Name2 :%s\n",pName2);
	/*printf("Phone : ");
	gets(name);

	printf("Address : ");
	gets(name);

	printf("Name: %s\n",name);
	printf("Address: %s\n",name);
	printf("Phone: %s\n",name);*/

}
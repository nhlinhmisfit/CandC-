#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct _member
{
	char	code[80];
	char	name[80];

}Mem, *pMember;

//Manager area 
Mem	*SearchMember(const char* vcode){
	FILE	*fp;
	const char *filename = "Mem.txt";
	char dummy[80]={0};
	char	code[80]={0};
	char	name[80]={0};
	Mem	*p;

	fp = fopen(filename,"r");
	if( fp == NULL )	{
		printf("Not found : %s \n", filename);
		return NULL;
	}
	fgets(dummy,sizeof(dummy), fp);
	while( EOF != fscanf(fp,"%s %s", code, name) ){
		if( strcmp(code, vcode) == 0 ){
			p = (Mem*)calloc(1,sizeof(Mem));
			strcpy(p->code,code);
			strcpy(p->name,name);
			return p;
		}
	}
	return NULL;
}
int	TimeStampProc(const char *vstr){
	FILE	*fp;
	const char *filename = "TimeStamp.txt";
	fp = fopen(filename, "a");
	fprintf(fp,"%s\n",vstr);
	fclose(fp);
	return 0;
}
int CountCode(const char *code)
{
	FILE *fp; 
	const char *filename = "TimeStamp.txt";
	char codet[80]= {0};
	int count =0;
	fp = fopen(filename,"r");
	while( EOF != fscanf(fp,"%s", codet) ){
		if( strcmp(codet, code) == 0 ){
			count +=1;
		}
	}
	return count;
}
int checkStatus(time_t nsec, const char* code){
	int state = 0;
	int	in_time = 9;
	int out_time = 18;

	int count =0;
	count = CountCode(code);
	count = count %2;

	struct tm *pt = localtime(&nsec);

	if(count ==0 )
	{
		if( pt->tm_hour < in_time || (pt->tm_hour ==in_time && pt->tm_min <10) )
		{
			state = 1;
		}
		else
			state =2;
	}
	else
	{
		if( pt->tm_hour < out_time ||(pt->tm_hour == out_time && pt->tm_min<50))
		{
			state = 3; 
		}
		else
			state = 4;
	}
	return state;
}
int usertime(time_t *pn, int hour, int min)
{
	struct tm user_date;

	time(pn);
	user_date = *localtime(pn);
	user_date.tm_hour = hour;
	user_date.tm_min = min;
	*pn = mktime(&user_date);

	return 0;
}
void ManageMode()
{
	char	message[2][512]={"GlobePoint IT Team"};
	char	action[][30]={"UNDFY","IN","Late","Early","OUT"};
	char	code[24]={0};

	Mem	*pMember;

	time_t	now;
	int status_no = 0;
	int hour, min;
	int count= 0;

	while(1){
		system("cls");
		puts(message[0]);
		puts(message[1]);
		puts("Please Your Card (exit)");
		memset(code,0,sizeof(code));//		code[0] = 0;
		gets(code);
		if(strcmp(code,"exit")==0)
			break;
		if( code[0] ){
			pMember = SearchMember(code);
			if( pMember != NULL ){

				printf("Input time (H:M): ");
				scanf("%d %d",&hour,&min);fflush(stdin);
				usertime(&now,hour,min);

				status_no = checkStatus(now,code);
				sprintf(message[1],"%s	%s . %u:%u	", pMember->code, pMember->name, hour,min);
				strcat(message[1],action[status_no]);
				TimeStampProc(message[1]);
			}
			else{

				message[1][0] = 0;
			}			
		}
	}
}
//Admin area 
void EditMember(Mem MemberArr[])
{
	//Mem MemberArr[100];
	FILE *fp;
	const char *filename= "Mem.txt";
	char code[80] = {0};
	char name[80] = {0};

	fp = fopen(filename,"r");
	if(fp ==NULL)
	{
		printf("can not open file");
	}
	int i=0;
		while(EOF!=fscanf(fp,"%s %s ", code, name))
		{
			strcpy(MemberArr[i].code,code);
			strcpy(MemberArr[i].name,name);
			i++;
		}
		int i1= i;
	fclose(fp);
	flushall();
	printf("input your code wan to edit:");
	gets(code);flushall();
	printf("input your name want to edit:");
	gets(name);flushall();

	fp = fopen(filename,"w");
	fputs("",fp);
	fclose(fp);
	fopen(filename,"a");

	for(int i= 0; i<i1;i++)
	{
		if(strcmp(MemberArr[i].code, code)==0)
		{
			memset(MemberArr[i].name,0,sizeof(MemberArr[i].name));
			strcpy(MemberArr[i].name,name);
			//MemberArr[i] = MemberArr[i+1];
		}
		fputs(MemberArr[i].code,fp);
		fputs("\t",fp);
		fputs(MemberArr[i].name,fp);
		fputs("\n",fp);
	//	printf("%s %s\n", MemberArr[i].code, MemberArr[i].name);
	}
	fclose(fp);
}
void CreatMember()
{
	pMember Member,temp;
	FILE *fp;
	const char *filename= "Mem.txt";
	char code[80]={0};
	char name[80]={0};
	fp=fopen(filename, "a");
	if(fp ==NULL)
	{
		printf("can not open file");
	}
	Member = (Mem *)malloc(sizeof(Mem));

	printf("\nCode: ");
	gets(Member->code); flushall();
	printf("Name: ");
	gets(Member->name); flushall();

	temp = SearchMember(Member->code);
	if(temp != NULL)
	{
		printf("The code already exist.\n" );
		free(Member);
		getch();
	}
	else
	{
		fprintf(fp,"%s\t", Member->code);
		fprintf(fp,"%s\n", Member->name);
		printf("Create successful.\n");
		getch();
		free(Member);
	}
	fclose(fp);	
}
void AdminMode()
{
	int select;
	Mem Arr[100];
	while(1)
	{
		system("cls");
		printf("\t1.Create new member.\n");
		printf("\t2.Edit information's member\n");
		printf("\t3.Exit\n");
		scanf("%d", &select); fflush(stdin);
		if(select ==3)
			break;
		if(select ==1)
		{
			CreatMember();
		}
		if(select == 2)
		{
			EditMember(Arr);
			break;
		}
	}
}

void main()
{
	int choose;
	
	while(1)
	{
		system("cls");
		printf("\t1.Start entrance manager\n");
		printf("\t2.Time Stamps\n");
		scanf("%d", &choose); fflush(stdin);
		if(choose ==0) break;
		if(choose == 1)
		{
			AdminMode();
		}
		if(choose ==2)
		{
			ManageMode();
		}
	}
}

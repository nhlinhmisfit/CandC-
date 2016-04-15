//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//	int start_time = 9;
//int end_time = 18;
//
//struct _member {
//	char code[24];
//	char name[80];
//}M;
//typedef struct _member *pM;
//
//pM SearchMember(const char* vcode)
//{
//	FILE *fp;
//	 char dummy[80] = {0};
//	 char code[24] = {0};
//	 char name[80] = {0};
//	 int rst;
//	 pM p;
//	const char  *filename = "member.txt";
//	fp = fopen(filename,"r");
//
//	if(fp ==NULL){
//		printf("not found");
//		return NULL;
//	}
//
//	fgets(dummy, sizeof(dummy),fp);
//	while( EOF != fscanf(fp,"%s %s ", code , name))
//	{
//		if(strcmp(code,vcode) ==0)
//		{
//			p = (pM)calloc (1,sizeof(M));
//			strcpy(p->code, code);
//			strpbrk(p->name,name);
//			return p;
//		}
//	}
//	_getch();
//	return NULL;
//}
//int SearchMembers(const char* vcode){
//	FILE *fp;
//	const char *filename = "Members.txt";
//	char code[512]={0};
//	char name[512]={0};
//	fp = fopen(filename, "r");
//	if( fp == NULL ){
//		printf("Not found : %s \n", filename);
//		return EOF;
//	}
//	while( fscanf(fp,"%s %s",code, name) ){
//		if( 0==strcmp(code, vcode) ){
//			fclose(fp);
//			return 1;// true;
//		}
//	}
//	fclose(fp);
//	return 0;
//}
//void TimeStampProc(const char *vcode, time_t time_stamp){
//	FILE *fp;
//	const char *filename = "TimeStamp.txt";
//	fp = fopen(filename, "a");
//	fprintf(fp,"%s %d \n", vcode, (unsigned int)time_stamp);
//	fclose(fp);
//	return;
//}
//int TimeCheck(time_t n){
//	int status_no;
//	struct tm t_date;
//	t_date = *localtime(&n);
//	if( t_date.tm_hour == 9 && t_date.tm_min < 10){
//		status_no = 0; // on time
//	}else{
//		status_no = 1; // late
//	}
//	if( t_date.tm_hour == 18 && t_date.tm_min > 10){
//		status_no = 0; // on time
//	}else{
//		status_no = 1; // late
//	}
//	return status_no;
//}
//int main( void ){
//	char message[2][512]={"GlobePoint IT Team"};
//	char code[24]={0};
//	time_t now;
//	char buf[100];
//	struct tm tdate;
//	pM pMember = NULL;
//	while(1){
//		system("cls");
//		puts(message[0]);
//		puts(message[1]);
//		puts("Please Your Card");
//		memset(code,0,sizeof(code));// code[0] = 0;
//		gets(code);
//
//		if( code[0] ){
//			if( 1==SearchMembers(code) ){
//				time(&now);
//				TimeStampProc(code,now);
//				strcpy(message[1],"Success save time stamp ");
//			}else{
//				strcpy(message[1],"Wrong Code !!!!");
//			}
//			//pMember = SearchMember(code);
//			//if(pMember != NULL)
//			//{
//			//	sprintf(message[1], "%s %s00", pMember->code, pMember->name);
//			//}
//			//else
//			//{
//			////	strcpy(message[1], "wrong code");
//			//	message[1][0] = 0;
//
//			//}		
//		}
//		_getch();
//	}
//	return 0;
//}

//time_t rawtime;
//struct tm * timeinfo;
//time (&rawtime);
//timeinfo = localtime (&rawtime );
//printf("%s",asctime(timeinfo) );
//printf("%d",TimeCheck(26));
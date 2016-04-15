//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//typedef struct _member{
//	char code[24];
//	char name[80];
//}M, *PM;
////typedef struct _member M;
////typedef struct _member *PM;
//
//PM SearchMember(const char* vcode){
//	FILE *fp;
//	const char *filename = "Members.txt";
//	char dummy[80]={0};
//	char code[80]={0};
//	char name[80]={0};
//	int rst;
//	M *p;
//	fp = fopen(filename,"r");
//	if( fp == NULL ) {
//		printf("Not found : %s \n", filename);
//		return NULL;
//	}
//	fgets(dummy,sizeof(dummy), fp);
//	while( EOF != fscanf(fp,"%s %s", code, name) ){
//		if( strcmp(code, vcode) == 0 ){
//			p = (M*)calloc(1,sizeof(M));
//			strcpy(p->code,code);
//			strcpy(p->name,name);
//			return p;
//		}
//	}
//	return NULL;
//}
//int TimeStampProc(const char *vstr, time_t timet)
//{
//	FILE *fp;
//	const char *filename = "TimeStamp.txt";
//	fp = fopen(filename, "a");
//	fputs(vstr,fp);
//	fclose(fp);
//	return 0;
//}
////int TimeCheck
//int main( void ){
//	char message[2][512]={"GlobePoint IT Team"};
//	char code[24]={0};
//	M *pMember;
//	time_t now;
//	struct tm * TimeInOut;
//	while(1){
//		system("cls");
//		puts(message[0]);
//		//puts(message[1]);
//		printf("%s",message[1]);
//		puts("Please Your Card");
//		memset(code,0,sizeof(code));// code[0] = 0;
//		gets(code);
//		if( code[0] ){
//			pMember = SearchMember(code);
//			if( pMember != NULL ){
//				time(&now);	
//				TimeInOut = localtime(&now);
//				sprintf(message[1],"%s %s .Time :%s", pMember->code, pMember->name, asctime(TimeInOut));
//				TimeStampProc(message[1], now);
//			}
//			else{
//				 strcpy(message[1],"Worng Code");
//				//message[1][0] = 0;
//			}
//		}
//	}
//	return 0;
//}
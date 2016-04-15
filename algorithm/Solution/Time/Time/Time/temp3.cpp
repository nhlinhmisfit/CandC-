//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//struct _member{
//	char code[24];
//	char name[80];
//};
//typedef struct _member M;
//typedef struct _member *PM;
//M *SearchMember(const char* vcode){
//	FILE *fp;
//	const char *filename = "Members.txt";
//	char dummy[80]={0};
//	char code[80]={0};
//	char name[80]={0};
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
//int TimeStampProc(const char *vstr){
//	FILE *fp;
//	const char *filename = "TimeStamp.txt";
//	fp = fopen(filename, "a");
//	// fputs(vstr, fp);
//	fprintf(fp,"%s\n",vstr);
//	fclose(fp);
//	return 0;
//}
////int checkStatus(time_t nsec){
////	int state = 0;
////	int in_time = 9;
////	int out_time = 18;
////	struct tm *pt = localtime(&nsec);
////	if(pt->tm_hour == in_time){
////		if(pt->tm_min <= 10){ state = 1; }
////		else { state = 2; }
////	}
////	if(pt->tm_hour == out_time){
////		if(pt->tm_min >= 50){ state = 4; }
////		else { state = 3; }
////	}
////	return state;
////}
//int GetCode(char *p){
//	int key;
//	int i;
//	for(i=0;i<23;++i){
//		key = _getch();
//		if( key == '\r') break;
//		p[i] = key;
//		_putch('*');
//	}
//	p[i]=0;
//	return 0;
//}
//int userTime(time_t *pn, int hour, int min){
//	struct tm user_date;
//	time(pn);
//	user_date = *localtime(pn);
//	user_date.tm_hour = hour;
//	user_date.tm_min = min;
//	*pn = mktime(&user_date);
//	return 0;
//}
//int CountCode(const char *code)
//{
//	FILE *fp; 
//	const char *filename = "TimeStamp.txt";
//	char codet[80]= {0};
//	int count =0;
//	fp = fopen(filename,"r");
//	while( EOF != fscanf(fp,"%s", codet) ){
//		if( strcmp(codet, code) == 0 ){
//			count +=1;
//		}
//	}
//	return count;
//}
//int checkStatus(time_t nsec, const char* code){
//	int state = 0;
//	int	in_time = 9;
//	int out_time = 18;
//
//	int count =0;
//	count = CountCode(code);
//	count = count %2;
//
//	struct tm *pt = localtime(&nsec);
//
//	if(count ==0 )
//	{
//		if( pt->tm_hour < in_time || (pt->tm_hour ==in_time && pt->tm_min <10) )
//		{
//			state = 1;
//		}
//		else
//			state =2;
//
//	}
//	else
//	{
//		if( pt->tm_hour < out_time ||(pt->tm_hour == out_time && pt->tm_min<50))
//		{
//			state = 3; 
//		}
//		else
//			state = 4;
//	}
//
//	return state;
//}
//int main( void ){
//	char message[2][512]={"GlobePoint IT Team"};
//	char action[][12]={"UNDFY","IN","Late","Early","OUT"};
//	char code[24]={0};
//	M *pMember;
//	time_t now;
//	int status_no = 0;
//	int hour, min;
//	while(1){
//		system("cls");
//		puts(message[0]);
//		puts(message[1]);
//		puts("Please Your Card");
//		memset(code,0,sizeof(code));// code[0] = 0;
//		gets(code);
//		if( code[0] ){
//			pMember = SearchMember(code);
//			if( pMember != NULL ){
//				// to test of rule time
//				printf("input time for test : (H M) : ");
//				scanf("%d %d", &hour, &min); fflush(stdin);
//				userTime(&now,hour,min);
//				status_no = checkStatus(now,code);
//				sprintf(message[1],"%s %s %u ", 
//					pMember->code, pMember->name, now);
//				strcat(message[1],action[status_no]);
//				TimeStampProc(message[1]);
//			}
//			else{
//				message[1][0] = 0;
//			}
//		}
//	}
//	return 0;
//}
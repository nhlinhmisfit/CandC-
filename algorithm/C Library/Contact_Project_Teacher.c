#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX	100

typedef struct _tel
{
	char name[15];
	char phone[15];
	int use;	// ¹øÁö »ç¿ë ¿©ºÎ
	int find;	// °Ë»ö¿¡¼­ »ç¿ë
}TEL;

TEL telbook[MAX] = {0};
int top = 0;

///////////////////////////////

int getnum(void);
void end(void);
void print(void);
void input(void);
void return_menu(void);
void help_input(void);
char yesno(void);
int search(int);
void search_no(void);
void search_telbook(int);
void init_telbook_find(void);
void print_telbook_find(void);
void modify_del(int);
void modify_telbook(int);
void file_save(void);
void file_load(void);
void sort_print(void);

////////////////////////////////

void main()
{
	while(1)
	{
		system("cls");
		printf("*** MENU ***\n");
		printf("1. INPUT\n");
		printf("2. PRINT\n");
		printf("   21. SORT PRINT(by name)\n");
		printf("3. SEARCH\n");
		printf("4. MODIFY\n");
		printf("5. DELETE\n");
		printf("6. FILE SAVE\n");
		printf("7. FILE LOAD\n");
		printf("8. EXIT\n");
		printf("CHOICE [  ]\b\b\b");

		switch(getnum())
		{
		case 1 : input(); break;
		case 2 : print(); break;
		case 3 : search(0); break;
		case 4 : modify_del(1); break;
		case 5 : modify_del(2); break;
		case 6 : file_save(); break;
		case 7 : file_load(); break;
		case 8 : end();
		case 21 : sort_print(); break;
		default : printf("Please choice again...\n");
			getch();
		}
	}
}

int getnum(void)
{
	char ch, ck = 0;
	int num = 0;
	while((ch = getchar()) != '\n')
	{
		num = num * 10 + ch -'0';
		ck = 1;
	}
	if(ck == 0)
		return -1;
	return num;
}

void end(void)
{
	system("cls");
	printf("\n\n\n\t\t");
	printf("Good - bye....\n");
	printf("\n\t\tProgram by hera...\n");
	exit(0);
}

void print(void)
{
	int i;

	system("cls");
	if(top == 0)
	{
		printf("\n\n\tEmpty Phone Book...\n");
		printf("\n\tPlease input contact infomation...\n");
	}
	else
	{
		printf("SEQ\t\tN A M E\t\tPhone\n");
		for(i = 0; i < MAX; i++)
		{
			if(telbook[i].use != 0)
				printf("%3d\t\t%s\t\t%s\n",
 i+1, telbook[i].name, telbook[i].phone);
		}
	}
	return_menu();
}	

void input(void)
{
	char name[15], phone[15];
	int no, i;
	char yn;
	help_input();
	system("cls");

	if(top == MAX)
	{
		printf("Memory Full ... \n");
		return_menu();
	}
	////////// ºó¹øÁö °è»ê... ////////

	for(i = 0; i < MAX; i++)
		if(telbook[i].use == 0)
			break;
	no = i+1;

	printf("\n\n\t   *** Add Contact Information Form ***\n\n");
	printf("\tSeq : [%d    ]\b\b\b\b\b\b", no);
	i = getnum();
	
	if(i > MAX)
	{
		printf("Cannot add new data..\n");
		return_menu();
		return;
	}
	else if(i != -1)
		no = i;	
	
	printf("\tN A M E: [               ]");
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	gets(name);

	printf("\tPhone : [               ]");
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	gets(phone);

	printf("\n\tSeq[%d] :: Name[%s] :: Phone[%s] \n", no, name, phone);
	printf("\tDo you save(y)? [  ]\b\b\b");
		
	yn = yesno();

	printf("\n\n\t");
	if(yn == 'Y' || yn == 'y')
	{
		if(telbook[no-1].use == 0)
		{
			strcpy(telbook[no-1].name, name);
			strcpy(telbook[no-1].phone, phone);
			telbook[no-1].use = 1;
			printf("Saved in Seq[%d]\n", no);
			top++;
		}
		else
		{
			printf("already exist Seq, Please re-input\n");
		}
	}
	else
	{
		printf("Cancled..\n");
	}
	
	return_menu();
}

void return_menu(void)
{	
	printf("\n\tPress any key for return Main menu...\n");
	getch();
}

void help_input(void)
{
	system("cls");

	printf("\n\n\t    < Manual for input>\n");
	printf("\n\n\tTo Automatic seq number press <enter>\n");
	printf("\n\tTo manual seq number \n");
	printf("\tinput 1~100 number\n");
	getch();
}

char yesno(void)
{
	char ch;

	ch = getchar();
	fflush(stdin);

	return ch;
}

int search(int mode)
{
	int no;
	system("cls");
	printf("*** SUB MENU ***\n");
	printf("1. ¹øÁö·Î %s\n", mode == 0 ? "°Ë»ö" : mode == 1 ? "¼öÁ¤" : "»èÁ¦");
	printf("2. °í°´ À̀¸§À¸·Î %s\n", mode == 0 ? "°Ë»ö" : mode == 1 ? "¼öÁ¤" : "»èÁ¦");
	printf("3. ÀüÈ­¹øÈ£·Î %s\n", mode == 0 ? "°Ë»ö" : mode == 1 ? "¼öÁ¤" : "»èÁ¦");
	printf("4. MAINÀ¸·Î µ¹¾Æ°¡±â\n");

	printf("Select[ ]\b\b");
	
	switch((no = getnum()))
	{
	case 1 : search_no(); break;
	case 2 : 
	case 3 : search_telbook(no); break;
	case 4 : return 1;
	}
	return 0;
}

void search_no(void)
{
	int no;
	system("cls");
	init_telbook_find(); // °Ë»ö¿©ºÎ¸¦ ĂÊ±âÈ­.....
	printf("°Ë»öÇÏ°íÀÚ ÇÏ´Â  ¹øÁö¸¦ ÀÔ·ÂÇÏ½Ă¿À : [     ]\b\b\b\b\b\b");
	no = getnum();

	if(telbook[no-1].use == 0)
		printf("°Ë»öÇÑ ¹øÁö[%d]´Â ºñ¾îÀÖ½À´Ï´Ù.\n", no);
	else
	{
		printf("°Ë»öÇÑ °á°ú....\n");
		printf("¹øÁö\t\tÀ̀    ¸§\t\tÀüÈ­¹øÈ£\n");
		printf("%3d\t\t%s\t\t%s\n", no, telbook[no-1].name, telbook[no-1].phone);
		telbook[no-1].find = 1;
	}
	return_menu();
}

void search_telbook(int mode)
{
	char buf[15];
	int i, cnt = 0;

	system("cls");
	init_telbook_find(); // °Ë»ö¿©ºÎ¸¦ ĂÊ±âÈ­.....

	printf("°Ë»öÇÏ°íÀÚ ÇÏ´Â %s ÀÔ·ÂÇÏ½Ă¿À : [               ]", mode == 2 ? "À̀¸§" : "ÀüÈ­¹øÈ£");
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	gets(buf);

	for(i = 0; i < MAX; i++)
	{
		if(mode == 2 && telbook[i].use == 1 && strcmp(telbook[i].name, buf) == 0)
		{
			telbook[i].find = 1;
			cnt++;
		}
		else if(mode == 3 && telbook[i].use == 1 && strcmp(telbook[i].phone, buf) == 0)
		{
			telbook[i].find = 1;
			cnt++;
		}
	}
	if(cnt == 0)
		printf("°Ë»öÇÑ %s[%s]´Â ÀüÈ­¹øÈ£ºÎ¿¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n", mode == 2 ? "À̀¸§" : "ÀüÈ­¹øÈ£", buf);
	else
	{
		printf("TOTAL [%d]°³°¡ °Ë»öµÇ¾ú½À´Ï´Ù...\n", cnt);
		print_telbook_find();
	}
	return_menu();			
}

void init_telbook_find(void)
{
	int i;
	for(i = 0; i < MAX; i++)
		telbook[i].find = 0;
}

void print_telbook_find(void)
{
	int i;
	printf("¹øÁö\t\tÀ̀    ¸§\t\tÀüÈ­¹øÈ£\n");
	for(i = 0; i < MAX; i++)
		if(telbook[i].find == 1)
			printf("%3d\t\t%s\t\t%s\n", i+1, telbook[i].name, telbook[i].phone);
}

void modify_del(int mode)	// mode == 1 ¼öÁ¤   mode == 2  »èÁ¦
{
	int no;
	char yn;
	if(search(mode) == 1)
		return;
	system("cls");
	printf("\n\n%sÇÏ±â À§ÇØ ¹øÁö¸¦ ÀÔ·ÂÇØÁÖ½Ê½Ă¿ä\n", mode == 1 ? "¼öÁ¤" : "»èÁ¦");
	printf("¸¸ÀÏ ¹øÁö¸¦ ±â¾ïÇÏÁö ¸øÇÑ´Ù¸é enter¸¦ ÀÔ·ÂÇØÁÖ½Ê½Ă¿ä\n");

	do			// enter¸¦ ÀÔ·ÂÇÏ¿´À» ½Ă....
	{
		printf("%sÇ̉ ¹øÁöÀÔ·Â [     ]\b\b\b\b\b\b",mode == 1 ? "¼öÁ¤" : "»èÁ¦");
		no = getnum();
		if( no == -1)
			print_telbook_find();
	}while(no == -1);
	
	if(telbook[no-1].find != 1)
		printf("°Ë»öÇÏÁø ³»¿ë°ú ÀÏÄ¡ÇÏÁö ¾Ê½À´Ï´Ù.\n");
	else
	{
		printf("¹øÁö[%d]  À̀¸§[%s]  ÀüÈ­¹øÈ£[%s]¸¦ %sÇÏ½Ă°Ú½À´Ï±î? [  ]\b\b\b",
			no, telbook[no-1].name, telbook[no-1].phone, mode == 1 ? "¼öÁ¤" : "»èÁ¦");
		if((yn = yesno()) == 'Y' || yn == 'y')
		{
			if(mode == 2)		// »èÁ¦ºÎºĐ...
			{
				telbook[no-1].use = 0;
				printf("»èÁ¦ÇÏ¿´½À´Ï´Ù.\n");
			}
			else				// ¼öÁ¤ºÎºĐ
				modify_telbook(no);
			
		}
		else
			printf("%s°¡(À̀) Ăë¼̉µÇ¾ú½À´Ï´Ù.\n",mode == 1 ? "¼öÁ¤" : "»èÁ¦");
	}
	return_menu();			
}

void modify_telbook(int no)
{
	int i;
	char buf[15];
	printf("\n\n\t   *** ÀüÈ­¹øÈ£ºÎ ¼öÁ¤ºÎ ***\n\n");
	printf("\t¹øÁö¼öÁ¤ : [%-5d]\b\b\b\b\b\b", no);
	i = getnum();
	if(i > 100)
	{
		printf("¹øÁö¼ö¸¦ ĂÊ°úÇÏ¿© ÀÔ·ÂÇÏ¼̀½À´Ï´Ù.\n");
		return;
	}
	else if(i != -1)
	{
		telbook[i-1] = telbook[no];
		telbook[no-1].use = 0;
		telbook[i-1].use = 1;
	}
	else
		i = no;

	printf("\tÀ̀¸§¼öÁ¤ : [%-15s]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", telbook[i-1].name);
	gets(buf);
	if(buf[0] != '\0')
		strcpy(telbook[i-1].name, buf);
	
	printf("\tÀüÈ­¹øÈ£ ¼öÁ¤ : [%-15s]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", telbook[i-1].phone);
	gets(buf);
	if(buf[0] != '\0')
		strcpy(telbook[i-1].phone, buf);
	printf("¹øÁö[%d] À̀¸§[%s] ÀüÈ­¹øÈ£[%s]·Î ¼öÁ¤ÇÏ¿´½À´Ï´Ù.", i, telbook[i-1].name, telbook[i-1].phone);
}

void file_save(void)
{
	FILE *fp;
	int i, cnt = 0;
	fp = fopen("telbook.txt", "w");
	if(fp == NULL)
		printf("¸̃¸đ¸®°¡ ºÎÁ·ÇÏ¿© È­ÀÏÀ» »ư¼ºÇ̉ ¼ö ¾ø½À´Ï´Ù.\n");
	else
	{
		for(i = 0; i < MAX; i++)
		{
			if(telbook[i].use == 1)
			{
				cnt++;
				fprintf(fp, "%d|%s|%s\n", i+1, telbook[i].name, telbook[i].phone);
			}
		}
		fclose(fp);
		printf("\n\n\t TOTAL [%d]°³ÀÇ ÀüÈ­¹øÈ£ºÎ¸¦ telbook.txt È­ÀÏ¿¡ ÀúÀåÇÏ¿´½À´Ï´Ù.\n", cnt);
	}
	return_menu();
}

void file_load(void)
{
	int i, no;
	char ch;
	FILE *fp;

	fp = fopen("telbook.txt", "r");
	if(fp == NULL)
		printf("È­ÀÏÀ» Ă£À» ¼ö°¡ ¾ø¾î ¿­Áö ¸øÇß½À´Ï´Ù.\n");
	else
	{
		top = 0;
		// »ç¿ëÁßÀÎ ¸̃¸đ¸® ¹øÁö ĂÊ±âÈ­....
		for(i = 0; i < MAX; i++)
			telbook[i].use = 0;
		while((ch = fgetc(fp)) != EOF)
		{
			no = 0;
			do
				no = no * 10 + ch -'0';
			while((ch = fgetc(fp)) != '|');
			i = 0;
			while((ch = fgetc(fp)) != '|')
				telbook[no-1].name[i++] = ch;
			telbook[no-1].name[i] = '\0';
			i = 0;
			while((ch = fgetc(fp)) != '\n')
				telbook[no-1].phone[i++] = ch;
			telbook[no-1].phone[i] = '\0';
			telbook[no-1].use = 1;
			top++;
		}
		fclose(fp);
		printf("TOTAL [%d]°³ÀÇ ÀüÈ­¹øÈ£ºÎ¸¦ ·ÎµåÇÏ¿´½À´Ï´Ù.\n", top);
	}
	return_menu();

}

void sort_print(void)
{
	int i, j, t = 0;
	TEL temp, sort[100] = {0};
	system("cls");
	for( i = 0 ; i < MAX; i++)
		if(telbook[i].use != 0)
		{
			sort[t++] = telbook[i];
			sort[t-1].find = i;
		}

	for( i = 0; i < t; i++)
	{
		for(j = i+1; j < t; j++)
			if(strcmp(sort[i].name, sort[j].name) >= 0)
			{
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
	}
	printf("À̀¸§À¸·Î Á¤·ÄÇÏ¿© Ăâ·ÂÇƠ´Ï´Ù.(¤¡,¤¤,¤§.. ¼ø¼­.)\n");
	
	printf("¹øÁö\t\tÀ̀    ¸§\t\tÀüÈ­¹øÈ£\n");
	for(i = 0; i < t; i++)
	{
		if(sort[i].use != 0)
			printf("%3d\t\t%s\t\t%s\n", sort[i].find+1, sort[i].name, sort[i].phone);
	}
	return_menu();
}
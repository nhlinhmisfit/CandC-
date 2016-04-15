#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX	100

typedef struct _tel
{
	char name[15];
	char phone[15];
	int use;	// ���� ��� ����
	int find;	// �˻����� ���
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
	////////// ����� ���... ////////

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
	printf("1. ������ %s\n", mode == 0 ? "�˻�" : mode == 1 ? "����" : "����");
	printf("2. �� �̸����� %s\n", mode == 0 ? "�˻�" : mode == 1 ? "����" : "����");
	printf("3. ��ȭ��ȣ�� %s\n", mode == 0 ? "�˻�" : mode == 1 ? "����" : "����");
	printf("4. MAIN���� ���ư���\n");

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
	init_telbook_find(); // �˻����θ� �ʱ�ȭ.....
	printf("�˻��ϰ��� �ϴ�  ������ �Է��Ͻÿ� : [     ]\b\b\b\b\b\b");
	no = getnum();

	if(telbook[no-1].use == 0)
		printf("�˻��� ����[%d]�� ����ֽ��ϴ�.\n", no);
	else
	{
		printf("�˻��� ���....\n");
		printf("����\t\t��    ��\t\t��ȭ��ȣ\n");
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
	init_telbook_find(); // �˻����θ� �ʱ�ȭ.....

	printf("�˻��ϰ��� �ϴ� %s �Է��Ͻÿ� : [               ]", mode == 2 ? "�̸�" : "��ȭ��ȣ");
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
		printf("�˻��� %s[%s]�� ��ȭ��ȣ�ο� �������� �ʽ��ϴ�.\n", mode == 2 ? "�̸�" : "��ȭ��ȣ", buf);
	else
	{
		printf("TOTAL [%d]���� �˻��Ǿ����ϴ�...\n", cnt);
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
	printf("����\t\t��    ��\t\t��ȭ��ȣ\n");
	for(i = 0; i < MAX; i++)
		if(telbook[i].find == 1)
			printf("%3d\t\t%s\t\t%s\n", i+1, telbook[i].name, telbook[i].phone);
}

void modify_del(int mode)	// mode == 1 ����   mode == 2  ����
{
	int no;
	char yn;
	if(search(mode) == 1)
		return;
	system("cls");
	printf("\n\n%s�ϱ� ���� ������ �Է����ֽʽÿ�\n", mode == 1 ? "����" : "����");
	printf("���� ������ ������� ���Ѵٸ� enter�� �Է����ֽʽÿ�\n");

	do			// enter�� �Է��Ͽ��� ��....
	{
		printf("%s�� �����Է� [     ]\b\b\b\b\b\b",mode == 1 ? "����" : "����");
		no = getnum();
		if( no == -1)
			print_telbook_find();
	}while(no == -1);

	if(telbook[no-1].find != 1)
		printf("�˻����� ����� ��ġ���� �ʽ��ϴ�.\n");
	else
	{
		printf("����[%d]  �̸�[%s]  ��ȭ��ȣ[%s]�� %s�Ͻðڽ��ϱ�? [  ]\b\b\b",
			no, telbook[no-1].name, telbook[no-1].phone, mode == 1 ? "����" : "����");
		if((yn = yesno()) == 'Y' || yn == 'y')
		{
			if(mode == 2)		// �����κ�...
			{
				telbook[no-1].use = 0;
				printf("�����Ͽ����ϴ�.\n");
			}
			else				// �����κ�
				modify_telbook(no);

		}
		else
			printf("%s��(��) ��ҵǾ����ϴ�.\n",mode == 1 ? "����" : "����");
	}
	return_menu();			
}

void modify_telbook(int no)
{
	int i;
	char buf[15];
	printf("\n\n\t   *** ��ȭ��ȣ�� ������ ***\n\n");
	printf("\t�������� : [%-5d]\b\b\b\b\b\b", no);
	i = getnum();
	if(i > 100)
	{
		printf("�������� �ʰ��Ͽ� �Է��ϼ̽��ϴ�.\n");
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

	printf("\t�̸����� : [%-15s]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", telbook[i-1].name);
	gets(buf);
	if(buf[0] != '\0')
		strcpy(telbook[i-1].name, buf);

	printf("\t��ȭ��ȣ ���� : [%-15s]\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", telbook[i-1].phone);
	gets(buf);
	if(buf[0] != '\0')
		strcpy(telbook[i-1].phone, buf);
	printf("����[%d] �̸�[%s] ��ȭ��ȣ[%s]�� �����Ͽ����ϴ�.", i, telbook[i-1].name, telbook[i-1].phone);
}

void file_save(void)
{
	FILE *fp;
	int i, cnt = 0;
	fp = fopen("telbook.txt", "w");
	if(fp == NULL)
		printf("�޸𸮰� �����Ͽ� ȭ���� ������ �� �����ϴ�.\n");
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
		printf("\n\n\t TOTAL [%d]���� ��ȭ��ȣ�θ� telbook.txt ȭ�Ͽ� �����Ͽ����ϴ�.\n", cnt);
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
		printf("can not read.\n");
	else
	{
		top = 0;
		// ������� �޸� ���� �ʱ�ȭ....
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
		printf("TOTAL [%d]doc file .\n", top);
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
		printf("�̸����� �����Ͽ� ����մϴ�.(��,��,��.. ����.)\n");

		printf("����\t\t��    ��\t\t��ȭ��ȣ\n");
		for(i = 0; i < t; i++)
		{
			if(sort[i].use != 0)
				printf("%3d\t\t%s\t\t%s\n", sort[i].find+1, sort[i].name, sort[i].phone);
		}
		return_menu();
}
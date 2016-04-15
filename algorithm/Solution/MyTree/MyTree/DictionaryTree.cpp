#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef struct _Object
{
	char *word;
	char *mean;
}OBJ;
typedef OBJ DATA;
typedef struct _Dictionary
{
	DATA data;
	struct _Dictionary *leftlink;
	struct _Dictionary *rightlink;
}DICT, *pDICT;

//DATA Process
void InputString(const char *pTitle, char **ppString)
{
	char temp[1024];
	printf("%s", pTitle);
	flushall();
	gets(temp);
	*ppString = (char *)malloc(strlen(temp)+1);
	strcpy(*ppString,temp);
}
DATA InputData()
{
	DATA data;
	char *str = "\0";
	InputString("New Word:",&data.word);
	InputString("Mean:", &data.mean);
	return data;
}
void PrintData(DATA data)
{
	printf("%s \n\tMean:[ %s]\n",data.word,data.mean );
}
//Tree Process
pDICT CreateWord(DATA data)
{
	pDICT temp;
	temp = (pDICT)malloc(sizeof(DICT));
	temp ->data =data;
	temp ->leftlink = NULL;
	temp ->rightlink = NULL;
	return temp;
}

pDICT AddWordTree(pDICT root, DATA data)
{
	pDICT NewWord;
	NewWord = CreateWord(data);
	if(root == NULL)
	{
		return NewWord;
	}
	else
	{
		if(strcmp(root->data.word,data.word)>0)
		{
			root->leftlink = AddWordTree(root->leftlink,data);
		}
		else
		{
			root->rightlink = AddWordTree(root->rightlink,data);
		}
	}
	return root;
}
pDICT MakeDictionary()
{
	pDICT root =NULL;
	DATA temp1,temp2;
	char *str = "\0";
	temp1 = InputData();
	root = CreateWord(temp1);
	while (1)
	{
		InputString("New Word:",&temp2.word);
		if(strcmp(temp2.word, str)==0)
			break;
		InputString("Mean's:", &temp2.mean);
		AddWordTree(root,temp2);
	}
	return root;
}
//Out Word
void Print(pDICT node)
{
	if(node == NULL)
		return;
	else
	{
		Print(node->leftlink);
		PrintData(node->data);
		Print(node->rightlink);
	}
}
void PrintDictionary(pDICT node)
{
	if(node == NULL)
		return;
	else
	{
		Print(node->leftlink);
		PrintData(node->data);
		Print(node->rightlink);
	}
}
int CountWord(pDICT root)
{
	if(root ==NULL)
	{
		return 0;
	}
	else
	{
		return(CountWord(root->leftlink)+ 1 + CountWord(root->rightlink));
	}

}
//Look Up Process
pDICT FindProcess(pDICT root, char KeyWord[])
{
	if(root == NULL)
	{
		return(false);
	}
	else
	{
		if(strcmp(KeyWord, root->data.word)==0)
			return(root);
		else
		{
			if(strcmp(KeyWord,root->data.word)<0)
				return(FindProcess(root->leftlink,KeyWord));
			else
				return(FindProcess(root->rightlink,KeyWord));
		}
	}
}
void LookUpWord(pDICT root)
{
	pDICT Look;
	char KeyWord[1024];
	printf("Enter Keyword look up: " );
	gets(KeyWord);
	flushall();
	Look = FindProcess(root,KeyWord);
	if(Look != false)	
		PrintData(Look->data);
	else
	{
		printf("The Word not exits");
	}
}
//Delete Word
pDICT FirstWord(pDICT root)
{
	pDICT temp = root;
	while(temp->leftlink != NULL)
	{
		temp = temp->leftlink;
	}
	return temp;

}
pDICT FindWord(pDICT root, char KeyWord[])
{
	if(root == NULL)
		return root;
	else
	{
		if(strcmp(KeyWord, root->data.word)<0)
			root ->leftlink = FindWord(root->leftlink, KeyWord);
		else
		{
			if(strcmp(KeyWord,root->data.word)>0)
				root->rightlink = FindWord(root->rightlink,KeyWord);
			else
			{
				if(root ->leftlink ==NULL && root->rightlink ==NULL) 
				{
				//	pDICT temp= NULL;
					//temp->leftlink= root;
					free(root);
					root = NULL;
				}
				else
				{
					if(root -> leftlink ==NULL)
					{//has right link
						pDICT temp = root;
						root = root->rightlink;
						free(temp);
					}
					else
					{
							if(root ->rightlink ==NULL)
							{//has left link
								pDICT temp = root;
								root = root->leftlink;
								free(temp);		
							} 
							else
							{//have two links
								pDICT temp = FirstWord(root->rightlink); 
								root->data = temp->data;			
								root ->rightlink = FindWord(root->rightlink,temp->data.word);				
							}
				}
			}
		}
	}
}
	return root;
}
//pDICT FindWord(pDICT root, char key[])
//{
//	if (root == NULL)
//		return root;
//	if(strcmp(key,root->data.word)<0)
//		root->leftlink = FindWord(root->leftlink,key);
//
//	else if(strcmp(key,root->data.word)>0)
//		root->rightlink =FindWord(root->rightlink,key);
//	else
//	{
//		if(root->leftlink==NULL)
//		{
//			pDICT temp = root ->rightlink;
//			free(root);
//			return temp;
//		}
//		else if(root->rightlink ==NULL)
//		{
//			pDICT temp = root->leftlink;
//			free(root);
//			return temp;
//		}
//		pDICT temp = FirstWord(root->rightlink);
//		root->data = temp ->data;
//		root ->rightlink = FindWord(root->rightlink,temp->data.word);
//	}
//	return root;
//}
void DeleteWord(pDICT root)
{
	pDICT temp;
	char Key[1024];
	printf("Enter Keyword to delete: " );
	gets(Key);
	flushall();
	temp = FindWord(root,Key);
	if(temp == root)
		printf("The word has been deleted.\n");
	else
		printf("No word in dictionary.\n");
}
//
void main()
{
	pDICT root =NULL;
	int iChoice =1;
	int Count;
	while(iChoice !=0)
	{
		system("cls");
		printf("\t1.Create your Dictionary.\n");
		printf("\t2.Load Dictionary.\n");
		printf("\t3.Look up word.\n");
		printf("\t4.Delete word.\n");
		scanf("%d", &iChoice);
		fflush(stdin);
		switch(iChoice)
		{
		case 1:
			root = MakeDictionary();  
			break;
		case 2: 
			PrintDictionary(root);
			Count = CountWord(root);
			printf("Dictionary have %d word.\n",Count);	
			break;
		case 3:
			LookUpWord(root);
			break;
		case 4: 
			DeleteWord(root);
			break;
		}
		getch();
	}
}
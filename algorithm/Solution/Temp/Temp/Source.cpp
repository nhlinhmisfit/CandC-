#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Object
{
	int i;
}OBJ;
typedef OBJ DATA;
typedef struct _Dictionary
{
	DATA data;
	struct _Dictionary *leftlink;
	struct _Dictionary *rightlink;
}DICT, *pDICT;

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
		if(root->data.i <data.i)
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
//int PrintWordMean(pDICT node)
//{
//	if(node == NULL) return 1;
//	printf("[ %s : %s]\n\t",node ->data.word,node->data.mean);
//	if(node ->leftlink)
//	{
//		printf("left[%s : %s]",node ->leftlink->data.word,node ->leftlink->data.mean);
//	}
//	if(node ->rightlink)
//	{
//		printf("	right[%s : %s]",node ->rightlink->data.word,node ->rightlink->data.mean);
//	}
//	printf("\n");
//	PrintWordMean(node ->leftlink);
//	PrintWordMean(node ->rightlink);
//	printf("");
//	return 0;
//}
void PrintTre(pDICT node)
{
	if(node ==NULL)
		return;
	PrintTre(node->leftlink);
	printf("[%d]\n",node ->data.i);
	PrintTre(node->rightlink);
}
void main()
{
	pDICT root =NULL;
	DATA temp1={1};

	root = (pDICT) malloc(sizeof(DICT));
	root->leftlink = root->rightlink = NULL;
	root ->data = temp1;

	{
		DATA temp2;
		while (1)
		{
			printf("so:");
			scanf("%d",&temp2.i);
			if(temp2.i == 0) break;
			flushall();
			AddWordTree(root,temp2);
		}
	}

	//PrintWordMean(root);
	PrintTre(root);
}
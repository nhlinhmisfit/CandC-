///////////////원형 연결 리스트 ///////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "circularlist.h"
#define TRUE 1
#define FALSE 0

typedef struct CircularListNodeType {
	int data;
	struct CircularListNodeType* pLink;
} CircularListNode;

typedef struct CircularListType {
	int currentElementCount;	// 현재 저장된 원소의 개수
	CircularListNode* pLink;	// 헤드 포인터(Head Pointer)
} CircularList;

///////////////////////////////////////////////////////////////////////////////
CircularList* createCircularList();
void deleteCircularList(CircularList* pList);
int addCLElement(CircularList* pList, int position, CircularListNode element);
int removeCLElement(CircularList* pList, int position);
void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList); //현재 연결 리스트 길이 
CircularListNode* getCLElement(CircularList* pList, int position);
void displayCircularList(CircularList* pList);
/////////////////////////////////////////////////////////////////////////////////
void main()
{
	int i = 0;
	int arrayCount = 0;
	CircularList *pList = NULL;
	CircularListNode *pValue = NULL;
	CircularListNode node;

	// 배열리스트 생성
	pList = createCircularList();
	if (pList != NULL)
	{
		node.data = 11;
		addCLElement(pList, 0, node);

		node.data = 33;
		addCLElement(pList, 1, node);

		node.data = 55;
		addCLElement(pList, 2, node);
		displayCircularList(pList);
		
		removeCLElement(pList, 0);

		node.data = 44;
		addCLElement(pList, 2, node);
		displayCircularList(pList);

		arrayCount = getCircularListLength(pList);

		for(i = 0; i < arrayCount; i++)
		{
			pValue = getCLElement(pList, i);
			printf("position[%d]-%d\n", i, pValue->data);
		}

	//	deleteCircularList(pList);
	}
	
}

int addCLElement(CircularList* pList, int position, CircularListNode element)
{
	int ret = FALSE;
	int i = 0;
	CircularListNode *pPreNode = NULL, *pNewNode = NULL, *pLastNode = NULL;


	if (pList != NULL) {

		if (position >= 0 && position <= pList->currentElementCount) {
		
			pNewNode = (CircularListNode*)malloc(sizeof(CircularListNode));
			
			if (pNewNode == NULL) {
				printf("오류, 메모리할당 addCLElement()\n");
				return ret;
			}
			*pNewNode = element;
			pNewNode->pLink = NULL;

			if (position == 0) 
			{
				if (pList->currentElementCount == 0)
				{
					pList->pLink = pNewNode;
					pNewNode->pLink = pNewNode;  //최초 자기 자신 노드 링크 
				}
				else 
				{
					pLastNode = pList->pLink;
					while(pLastNode->pLink != pList->pLink) 
					{
						pLastNode = pLastNode->pLink;
					}
					pList->pLink = pNewNode;
					pNewNode->pLink = pLastNode->pLink;
					pLastNode->pLink = pNewNode;
				}
			}
			else 
			{
				pPreNode = pList->pLink;
				for(i = 0; i < position - 1; i++) 
				{	//printf("-1-");
					pPreNode = pPreNode->pLink;
				}
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}
			pList->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] addCLElement()\n", position);
		}
	}

	return ret;
}

int removeCLElement(CircularList* pList, int position)
{
	int ret = FALSE;
	int i = 0, arrayCount = 0;
	CircularListNode *pPreNode = NULL, *pDelNode = NULL, *pLastNode = NULL;

	if (pList != NULL) {

		arrayCount = getCircularListLength(pList);  //ret 3 return 

		if (position >=0 && position < arrayCount) 	{
			if (position == 0) {
				pDelNode = pList->pLink;
				if (arrayCount == 1) {
					free(pDelNode);
					pList->pLink = NULL;
				}
				else {
					pLastNode = pList->pLink;
					while(pLastNode->pLink != pList->pLink) {
						pLastNode = pLastNode->pLink;
					}
					pLastNode->pLink = pDelNode->pLink;
					pList->pLink = pDelNode->pLink;
					free(pDelNode);
				}
			}
			else {
				pPreNode = pList->pLink;
				for(i = 0; i < position - 1; i++) {
					pPreNode = pPreNode->pLink;
				}
				pDelNode = pPreNode->pLink;
				pPreNode->pLink = pDelNode->pLink;
				free(pDelNode);
			}
			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] removeCLElement()\n", position);
		}
	}

	return ret;
}

CircularListNode* getCLElement(CircularList* pList, int position) {
	int i = 0;
	CircularListNode* pNode = NULL;
	if (pList != NULL) {
		if (position >=0 && position < pList->currentElementCount) {
			pNode = pList->pLink;
			for(i = 0; i < position; i++) {
				pNode = pNode->pLink;
			}
		}
	}

	return pNode;
}
// 원형 연결 리스트 생성 
CircularList* createCircularList() {  
	CircularList *pReturn = NULL;
	int i = 0;

	pReturn = (CircularList *)malloc(sizeof(CircularList));

	if (pReturn != NULL) {  // 노드를 초기화 하기 위한 작업 

		memset(pReturn, 0, sizeof(CircularList));
	}
	else {
		printf("오류, 메모리할당 createCircularList()\n");
		return NULL;
	}
	return pReturn;
}

void displayCircularList(CircularList* pList)
{
	int i = 0;
	if (pList != NULL) {
		printf("현재 원소 개수: %d\n", pList->currentElementCount);
		for(i = 0; i < pList->currentElementCount; i++) {
			printf("[%d],%d\n", i, getCLElement(pList, i)->data);
		}
	}
	else {
		printf("원소가 없습니다.\n");
	}
}

int getCircularListLength(CircularList* pList)
{
	int ret = 0;
	if (pList != NULL) {
		ret = pList->currentElementCount;
	}
	return ret;
}

void deleteCircularList(CircularList* pList)
{
	if (pList != NULL) {
		clearCircularList(pList);
		free(pList);
	}
}

void clearCircularList(CircularList* pList)
{
	if (pList != NULL) {
		while (pList->currentElementCount > 0) 		{
			removeCLElement(pList, 0);
		}
	}
}













//////////////////////이중 연결리스트////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "doublylist.h"
#define TRUE		1
#define FALSE		0

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;		// 현재 저장된 원소의 개수
	DoublyListNode	headerNode;		// 헤더 노드(Header Node)
} DoublyList;

DoublyList* createDoublyList();
void deleteDoublyList(DoublyList* pList);
int addDLElement(DoublyList* pList, int position, DoublyListNode element);
int removeDLElement(DoublyList* pList, int position);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);
DoublyListNode* getDLElement(DoublyList* pList, int position);
void displayDoublyList(DoublyList* pList);


void main()
{
	int i = 0;
	int arrayCount = 0;
	DoublyList *pList = NULL;
	DoublyListNode *pValue = NULL;
	DoublyListNode node = {0,};

	// 배열리스트 생성
	pList = createDoublyList();
	if (pList != NULL)
	{
		node.data = 11;
		addDLElement(pList, 0, node);
		node.data = 33;
		addDLElement(pList, 1, node);
		node.data = 55;
		addDLElement(pList, 2, node);
		displayDoublyList(pList);

		removeDLElement(pList, 0);
		displayDoublyList(pList);

		deleteDoublyList(pList);
	}
}

DoublyList* createDoublyList()
{
	DoublyList *pReturn = NULL;
	int i = 0;

	pReturn = (DoublyList *)malloc(sizeof(DoublyList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(DoublyList));

		pReturn->headerNode.pLLink = &(pReturn->headerNode);
		pReturn->headerNode.pRLink = &(pReturn->headerNode);
	}
	else {
		printf("오류, 메모리할당 createDoublyList()\n");
		return NULL;
	}

	return pReturn;
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	int ret = FALSE, i = 0;
	DoublyListNode *pPreNode = NULL, *pNewNode = NULL, *pTempNode = NULL;
	
	if (pList != NULL) 	{
		if (position >= 0 && position <= pList->currentElementCount) 
		{

			pNewNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));

			if (pNewNode == NULL) 
			{
				printf("오류, 메모리할당 addCLElement()\n");
				return ret;
			}
			*pNewNode = element;
			pNewNode->pLLink = NULL;
			pNewNode->pRLink = NULL;

			pPreNode = &(pList->headerNode);

			for(i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}

			pNewNode->pLLink = pPreNode;
			pNewNode->pRLink = pPreNode->pRLink;
			pPreNode->pRLink = pNewNode;
			pNewNode->pRLink->pLLink = pNewNode;

			pList->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] addDLElement()\n", position);
		}
	}

	return ret;
}

int removeDLElement(DoublyList* pList, int position)
{
	int ret = FALSE;
	int i = 0, arrayCount = 0;
	DoublyListNode *pPreNode = NULL, *pDelNode = NULL, *pTempNode = NULL;
	
	if (pList != NULL) 	{
		arrayCount = getDoublyListLength(pList);
		if (position >=0 && position < arrayCount) 	{
			pPreNode = &(pList->headerNode);
			for(i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}
			pDelNode = pPreNode->pRLink;

			pPreNode->pRLink = pDelNode->pRLink;
			pDelNode->pRLink->pLLink = pPreNode;
			free(pDelNode);

			pList->currentElementCount--;
			ret = TRUE;
		}
		else
		{
			printf("오류, 위치 인덱스-[%d] removeDLElement()\n", position);
		}
	}

	return ret;
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode* pReturn = NULL;
	int i = 0;
	DoublyListNode* pNode = NULL;
	if (pList != NULL) {
		if (position >=0 && position < pList->currentElementCount) 	{
			pNode = pList->headerNode.pRLink;
			for(i = 0; i < position; i++) {
				pNode = pNode->pRLink;
			}
			pReturn = pNode;
		}
		else {
			printf("오류, 위치 인덱스-[%d] getDLElement()\n", position);
		}
	}

	return pReturn;
}

void displayDoublyList(DoublyList* pList)
{
	int i = 0;
	if (pList != NULL) {
		printf("현재 노드 개수: %d\n", pList->currentElementCount);

		for(i = 0; i < pList->currentElementCount; i++) {
			printf("[%d],%d\n", i, getDLElement(pList, i)->data);
		}
	}
	else {
		printf("원소가 없습니다.\n");
	}
}

void deleteDoublyList(DoublyList* pList)
{
	if (pList != NULL) {
		clearDoublyList(pList);
		free(pList);
	}
}

void clearDoublyList(DoublyList* pList)
{
	if (pList != NULL) {
		while (pList->currentElementCount > 0) {
			removeDLElement(pList, 0);
		}
	}
}

int getDoublyListLength(DoublyList* pList)
{
	int ret = 0;
	if (pList != NULL) {
		ret = pList->currentElementCount;
	}
	return ret;
}



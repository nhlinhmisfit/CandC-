#include <stdio.h>
#include<malloc.h>
#include <string.h>
typedef struct _MEMBER 
{
	char * m_Name;
	char * m_Address;
	char * m_TelNo;

}MEMBER;
void InputString(const char * pTitle, char **ppString)
{
	char temp[1024];

	printf("%s: ", pTitle);
	gets(temp);
	*ppString = (char *) malloc(strlen(temp) +1);
	strcpy(*ppString, temp);

}

void InputMember(MEMBER MemArray[], int *piIndex, int iArraySize) //pointer
{
	if(*piIndex >= iArraySize)
	{
		printf("can't add new member, buffer is full");
		return;
	}
	char temp[1024];

	InputString("Name", &MemArray[*piIndex].m_Name);
	InputString("Address", &MemArray[*piIndex].m_Address);
	InputString("TelNo", &MemArray[*piIndex].m_TelNo);

	++(*piIndex);
}
void InpuMemberData(MEMBER	*pMEmber)
{
	InputString("Name",&pMEmber ->m_Name);
	InputString("Address",&pMEmber ->m_Address);
	InputString("TelNo", &pMEmber ->m_TelNo);
}
void PrintMemberData(MEMBER MemArray[], int i )
{
	printf("Name : %s\n", MemArray[i].m_Name);
	printf("TelNo : %s\n", MemArray[i].m_Address);
	printf("TelNo : %s\n", MemArray[i].m_TelNo);   //same code will change much 
} // stupid code

void PrintMemberData1(MEMBER *pMember)
{
	printf("Name : %s\n", pMember->m_Name);
	printf("TelNo : %s\n", pMember->m_Address);
	printf("TelNo : %s\n", pMember->m_TelNo);   //same code will change much 
}

void PrintAll(MEMBER MemArray[], int iIndex)
{
	for ( int i = 0 ; i < iIndex; ++i)
	{
		//PrintMemberData(MemArray,i);
		PrintMemberData1(&MemArray[i]);
	}
}

int SearchMemberData(MEMBER MemArray[], int iIndex, char *Name)
{

	for(int i = 0 ; i< iIndex;  ++i)
	{
		if(strcmp(MemArray[i].m_Name , Name)== 0)
			return i;
	}
	return -1;
}
void Search(MEMBER MemArray[],int iIndex)
{
	char Name[1024];
	printf("Name: ");
	gets(Name);
	int iSearch = SearchMemberData(MemArray, iIndex,Name);
	if(iSearch != -1)
	{
		PrintMemberData1(&MemArray[iSearch]);
	}
	else
	{
		printf("Not Found!!!\n");
	}
	
}
void MultiSearchMemberData(MEMBER MemArray[], int iIndex, char *Name,int * iResultArray,int  *piResultCount) 
	//int * piResultArray == int  piResultArray[]
{
	*piResultCount = 0;
	for(int i = 0 ; i<iIndex; ++i)
	{
		if(strstr(MemArray[i].m_Name, Name) != NULL)
		{
			iResultArray[*piResultCount] =i;
			++(*piResultCount);
		}
	}
}
void PrintMultiSearchResult(MEMBER MemArray[],int iResultArray[],int iResultCount)
{
	for(int i =0 ; i< iResultCount; ++i)
	{
		PrintMemberData1(&MemArray[iResultArray[i]]);
	}
}
void MultiSearch(MEMBER MemArray[],int iIndex)
{
	char Name[1024];
	printf("Finding String in Name: ");
	gets(Name);
	
	int *iResultArray = (int *)malloc(sizeof(int) *iIndex);
	int iResultCount = 0;

	MultiSearchMemberData(MemArray, iIndex,Name, iResultArray, &iResultCount);

	if(iResultCount ==0)
	{
		printf("Not Found!!!\n");
	}
	else
	{
		PrintMultiSearchResult(MemArray,iResultArray,iResultCount);
	}
	free(iResultArray);
}

void FreeMemberData(MEMBER * pMember)
{
	free(pMember->m_Name);
	free(pMember->m_Address);
	free(pMember->m_TelNo);
}
void Modify(MEMBER MemArray[], int iIndex)
{
	char Name[1024];
	printf("Name: ");
	gets(Name);
	int iSearch = SearchMemberData(MemArray, iIndex,Name);
	if(iSearch != -1)
	{
		FreeMemberData(&MemArray[iSearch]);
		InpuMemberData(&MemArray[iSearch]);
	}
	else
	{
		printf("Can not modify!!!\n");
	}
}
int  DeleteAt(MEMBER MemArray[], int *piIndex, int iSearch)
{
	if(*piIndex ==0 || (iSearch < 0 && iSearch >= *piIndex))
	{
		return 0;
	}
	FreeMemberData(&MemArray[iSearch]);
	memcpy(&MemArray[iSearch],&MemArray[iSearch +1],sizeof(MEMBER)* (*piIndex -iSearch -1) );
	--(*piIndex);
	return 1;
}
void Delete(MEMBER MemArray[], int *piIndex)
{
	char Name[1024];
	printf("Name: ");
	gets(Name);
	int iSearch = SearchMemberData(MemArray, *piIndex, Name);
	if(iSearch != -1)
	{
		/*FreeMemberData(&MemArray[iSearch]);
		memcpy(&MemArray[iSearch],&MemArray[iSearch +1],sizeof(MEMBER)* (*piIndex -iSearch -1) );
		--(*piIndex);*/
		DeleteAt(MemArray, piIndex, iSearch);
	}
	else
	{
		printf("Not found !!!\n");
	}
}
void DeleteAllMembers(MEMBER MemArray[], int * piIndex)
{
	while (DeleteAt(MemArray,piIndex,*piIndex -1));
}
void DeleteMultiData(MEMBER MemArray[],int iResultArray[], int iResultCount, int *piIndex)
{
	for(int i = iResultCount -1 ; i>=0; --i)
	{
		DeleteAt(MemArray, piIndex,iResultArray[i]);
	}
}
void MultiDelete(MEMBER MemArray[], int *piIndex)
{
	char Name[1024];
	printf("Finding String in Name: ");
	gets(Name);

	int *iResultArray = (int *)malloc(sizeof(int )* (*piIndex));
	int iResultCount =0;

	MultiSearchMemberData(MemArray, *piIndex,Name,iResultArray, &iResultCount);
	if(iResultCount ==0)
	{
		printf("Not Found!!!");
	}
	else 
	{
		PrintMultiSearchResult(MemArray,iResultArray,iResultCount);
		DeleteMultiData(MemArray,iResultArray,iResultCount,piIndex);
	}
}
void main()
{
	MEMBER MemArray[3];
	int iIndex =0;
	int iChoice =1 ; 
	while ( iChoice != 0)
	{
		printf("1. Input\n");
		printf("2. Print All\n");
		printf("3. Search\n");
		printf("4. Modify\n");
		printf("5. Delete\n");
		printf("6. Multiple Search\n");
		printf("7. Multiple Delete\n");
		scanf("%d", &iChoice);
		fflush(stdin);	
		switch (iChoice)
		{
		case 1: 
			InputMember(MemArray, &iIndex,sizeof(MemArray)/sizeof(MemArray[0])); // name address
			break;
		case 2: 
			PrintAll(MemArray, iIndex);
			break;
		case 3:
			Search(MemArray, iIndex);
		case 4: 
			Modify(MemArray, iIndex);
			break;
		case 5: 
			Delete(MemArray, &iIndex);
			break;
		case 6:
			MultiSearch(MemArray,iIndex);
			break;
		case 7: 
			MultiDelete(MemArray,&iIndex);
			break;
		}
	}
	DeleteAllMembers(MemArray,&iIndex);
}

#include <stdio.h>
#include <malloc.h>
#include<string.h>

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
	*ppString = (char *)malloc()
}

void main()
{

}
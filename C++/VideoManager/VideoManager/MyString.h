
#ifndef MYSTRING
#define MYSTRING
#include <iostream>
using namespace std;

#define  DEBUG_MODE

class MyString 
{
private:
	char * m_pData;
	int m_iLength;
public:
	MyString();
	~MyString();
	MyString(const MyString &rsh);
	MyString(const char *pData);
	char *GetData()const
	{
		return m_pData;
	}
	int GetLength()const 
	{
		return m_iLength;
	}
	MyString &operator=(const MyString &rsh);
	MyString operator+(const MyString &rsh);
	MyString & operator+=(const MyString &rsh);
};




#endif
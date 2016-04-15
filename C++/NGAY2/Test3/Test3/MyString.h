//#pragma once

#ifndef MYSTRING
#define  MYSTRING
#include <iostream>
using namespace std;

#define  DEBUG_MODE

class MyString
{
private: 
	char * m_pData;
	int m_iLength;
public:	
	MyString()
	{
#ifdef DEBUG_MODE
		cout<<"MyString()"<<endl;
#endif
		this->m_iLength = 0;
		this->m_pData = new char[1];
		*this->m_pData = NULL;
	}
	~MyString()
	{
#ifdef DEBUG_MODE
		cout<<"~MyString()"<<endl;
#endif
		delete []m_pData;
	}
	MyString (const MyString &rsh)
	{

#ifdef DEBUG_MODE
		cout<<"MyString (const MyString &rsh)"<<endl;
#endif

		m_iLength = rsh.m_iLength;
		m_pData = new char [m_iLength +1];
		strcpy(m_pData,rsh.m_pData);
	//	strcpy_s(m_pData, sizeof(rsh.m_pData +1),rsh.m_pData);

	}
	MyString (const char *pData)
	{
#ifdef DEBUG_MODE
		cout<<"MyString (const char *pData)"<<endl;
#endif

		this ->m_iLength = strlen(pData);
		this-> m_pData = new char [this->m_iLength +1];
		strcpy(this -> m_pData,pData);
	}
	char *GetData() const
	{
		return m_pData;
	}
	MyString & operator=(const MyString &rsh)
	{
		if(this == &rsh)
		{
			return *this;
		}
		delete [] m_pData;	
		m_iLength = rsh.m_iLength;
		m_pData = new char [m_iLength +1];
		strcpy(m_pData, rsh.m_pData);

		return *this;
	}
	MyString operator+(const MyString &rsh) //operator overloading
	{
		/*MyString s;
		delete [] s.m_pData;
		s.m_iLength = m_iLength +rsh.m_iLength;
		s.m_pData = new char[s.m_iLength +1];
		strcpy(s.m_pData,m_pData);
		strcat(s.m_pData,rsh.m_pData);*/
		MyString s(m_pData);
		s+= rsh;
		return s;
	}
	MyString & operator+=(const MyString &rsh)
	{
		m_iLength +=rsh.m_iLength;
		char *pData = new char[m_iLength+1];

		strcpy(pData, m_pData);
		strcat(pData, rsh.m_pData);

		delete []m_pData;
		m_pData = pData;

		return *this;
	}
	bool operator==(const MyString &rsh)
	{
		return strcmp(m_pData, rsh.m_pData) ==0;
	}
	bool operator!=(const MyString &rsh)
	{
		return !(*this ==rsh);
	}
	bool operator>(const MyString &rsh)
	{
		return strcmp(m_pData, rsh.m_pData) >0;
	}
	bool operator<=(const MyString &rsh)
	{
		return !(*this > rsh);
	}
	bool operator<(const MyString &rsh)
	{
		return strcmp(m_pData, rsh.m_pData) <0;
	}
	bool operator>=(const MyString &rsh)
	{
		return !(*this < rsh);
	}
	int GetLength() const
	{
		return m_iLength;
	}
	char operator[](int iIndex) const
		// const MyString *const this
	{
		return m_pData[iIndex];
	}
	char & operator[](int iIndex)
		//MyString *const this
	{
		return m_pData[iIndex];
	}

};
ostream & operator<<(ostream & o, const MyString & rsh);
istream & operator>>(istream & i,  MyString &rsh);
#endif
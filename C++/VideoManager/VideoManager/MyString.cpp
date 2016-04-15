#include "MyString.h"

MyString::MyString()
{
#ifdef DEBUG_MODE
	cout<<"MyString()"<<endl;
#endif
	this-> m_iLength =0;
	this-> m_pData = new char[1];
	*this->m_pData = NULL;
}
MyString::~MyString()
{
#ifdef DEBUG_MODE
	cout<<"~MyString()"<<endl;
#endif
	delete []m_pData;
}

MyString::MyString(const MyString &rsh)
{
#ifdef DEBUG_MODE
	cout<<"MyString(const MyString &rsh)"<<endl;
#endif

	m_iLength = rsh.m_iLength;
	m_pData = new char[m_iLength +1];
	strcpy_s(m_pData, sizeof(rsh.m_pData),rsh.m_pData);
}

MyString::MyString(const char *pData)
{
#ifdef DEBUG_MODE
	cout<<"MyString(const char *pData)"<<endl;
#endif

	this->m_iLength = strlen(pData);
	this->m_pData = new char[this->m_iLength +1];
	strcpy_s(this->m_pData,sizeof(pData),pData);
}
MyString& MyString::operator=(const MyString &rsh)
{
	if(this ==&rsh)
	{
		return *this;
	}
	delete []m_pData;
	m_iLength = rsh.m_iLength;
	m_pData= new char[m_iLength +1];
	strcpy_s(m_pData,sizeof(rsh.m_pData),rsh.m_pData);
	
	return *this;
}
MyString MyString::operator+(const MyString &rsh)
{
	MyString s(m_pData);
	s+= rsh;
	return s;
}
MyString& MyString::operator+=(const MyString &rsh)
{
	m_iLength +=rsh.m_iLength;
	char *pData = new char[m_iLength+1];

	strcpy_s(pData,sizeof(m_pData),m_pData);
	strcat_s(pData,sizeof(rsh.m_pData),rsh.m_pData);

	delete []m_pData;
	m_pData = pData;
	 
	return *this;
}
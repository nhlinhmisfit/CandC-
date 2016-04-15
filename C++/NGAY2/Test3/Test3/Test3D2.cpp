#include<iostream>
using namespace  std;
#include "MyString.h"

class Member
{

public: 
	void InputData()
	{
		cout<<"Name: ";
		cin>>m_Name;
		cout<<"Add: ";
		cin>>m_add;
		cout<<"Tel: ";
		cin>>m_tel;
	}
	void PrintData() const
	{
		cout<<"Name: "<<m_Name<<endl;
		cout<<"Add: "<<m_add<<endl;
		cout<<"Tel: "<<m_tel<<endl;

	}
	bool CompareName(const MyString &Name) 
	{
		return m_Name == Name;
	}
private:
	MyString m_Name;
	MyString m_add;
	MyString m_tel;
};

class MemberMgr
{
private:
	Member **m_MemArray;
	int m_iMaxArray;
	int m_iIndex;

public:
	MemberMgr(int iMaxArray = 100)
	{
		m_iMaxArray = iMaxArray;
		m_iIndex = 0;
		m_MemArray = new Member *[m_iMaxArray];
	}
	~MemberMgr()
	{
		while(DeleteAt(m_iIndex -1));
	}
	void Input()
	{
		if(m_iIndex >= m_iMaxArray)
		{
			cout<<"Can't add new member "<<endl;
			return;
		}
		Member * pMember = new Member;
		pMember->InputData();
		m_MemArray[m_iIndex] = pMember;
		++m_iIndex;
	}
	void Print()
	{
		for(int i = 0 ; i <m_iIndex; ++i)
		{
			m_MemArray[i] ->PrintData();
		}
	}
	int SearchMember(const MyString &SearchName) //
	{
		for(int i= 0 ; i < m_iIndex; ++i)
		{
			if(m_MemArray[i]->CompareName(SearchName))
			{
				return i;
			}
		}
		return -1; 
	}
	void Search()
	{
		MyString Name;
		cout<<"Name for search: ";
		cin>>Name;
		int iSearchIndex = SearchMember(Name);
		
		if(iSearchIndex == -1)
		{
			cout<<"can't found"<<endl;
		}
		else
		{
			m_MemArray[iSearchIndex]->PrintData();
		}
	}
	void Modify()
	{
		MyString Name;
		cout<<"Name for search: ";
		cin>>Name;
		int iSearchIndex = SearchMember(Name);

		if(iSearchIndex == -1)
		{
			cout<<"can't found"<<endl;
		}
		else
		{
			m_MemArray[iSearchIndex]->InputData();
		}
	}
	void Delete()
	{
		MyString Name;
		cout<<"Name for search: ";
		cin>>Name;
		int iSearchIndex = SearchMember(Name);

		if(iSearchIndex == -1)
		{
			cout<<"can't found"<<endl;
		}
		else
		{
			DeleteAt(iSearchIndex);
		}
	}
	bool DeleteAt(int iSearchIndex)
	{
		if(m_iIndex ==0)
		{
			return false;
		}
		delete m_MemArray[iSearchIndex];
		memcpy(&m_MemArray[iSearchIndex],
			&m_MemArray[iSearchIndex+1],
			sizeof(Member *)*(m_iIndex-iSearchIndex -1));

		--m_iIndex;
		return true;
	}
	void Menu()
	{
		int iChoice =1;
		while(iChoice !=0)
		{
			cout<<"1. Input"<<endl;
			cout<<"2. Print"<<endl;
			cout<<"3. Search"<<endl;
			cout<<"4. Modify"<<endl;
			cout<<"5. Delete"<<endl;

			cin>>iChoice;
			cin.ignore(1);
			switch(iChoice)
			{
			case 1: 
				Input();
				break;
			case 2: 
				Print();
				break;
			case 3: 
				Search();
				break;
			case 4: 
				Modify();
				break;
			case 5: 
				Delete();
				break;
			}
		}
	}
};
void main()
{
	//MyString s1("Hello ");
	//MyString s2("World!!!");
	//MyString s3;
	//cout<<"s1.GetData():"<< s1.GetData()<<endl;
	//cout<<"s2.GetData():"<< s2.GetData()<<endl;
	//cout<<"s3.GetData():"<< s3.GetData()<<endl;

	//cout<<"=================================="<<endl;
	////s3 = s1 + s2; //s3= s1.operator=(s2);
	//if(s1 < s2)
	//{
	//	cout<<"s1 == s2"<<endl;
	//}
	//else
	//{
	//	cout<<"s1 != s2"<<endl;
	//}
	//cout<<"=================================="<<endl;

	//cout<<"s1.GetData():"<< s1.GetData()<<endl;
	//cout<<"s2.GetData():"<< s2.GetData()<<endl;
	//cout<<"s3.GetData():"<< s3.GetData()<<endl;
	
	//MyString s1("1234567890");
	//s1[0]='a';//s1.operator[](0) = 'a'
	//for(int i = 0; i<s1.GetLength();++i)
	//{
	//	cout<<s1[i]<<endl;
	//	//cout<<s1.operator[](i) <<endl;
	//}
	//char *pData  = "1234567890";
	//for(int i= 0; i <strlen (pData); ++i)
	//{
	//	cout<<pData[i] <<endl;
	//}

	/*MyString s1("1235325435");
	cout<<s1;*/
	
	/*MyString Name;

	cout<<"Name :" <<endl;
	cin>>Name;
	cout<<"Name: " <<Name<<endl;*/

	/*Member m1; 
	m1.InputData();
	m1.PrintData();*/

	int iMaxCount;
	cout<<"How many member in your company";
	cin>>iMaxCount;
	cin.ignore(1);

	MemberMgr m(iMaxCount);
	m.Menu();
}
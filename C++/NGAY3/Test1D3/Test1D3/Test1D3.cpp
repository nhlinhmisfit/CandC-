#include <iostream>
using namespace  std;
#include "MyString.h"

class MyStringArray
{
private: 
	MyString *m_pData;
	int m_iMaxArray;
	int m_iIndex;
public: 
	MyStringArray(int iMaxArray = 10)
	{
		m_iMaxArray = iMaxArray;
		m_iIndex = 0;
		m_pData = new MyString[m_iMaxArray];
	}
	~MyStringArray()
	{
		delete [] m_pData;
	}
	bool InsertData(const MyString &rsh)
	{
		if(m_iIndex >= m_iMaxArray)
		{
			return false;
		}
		m_pData[m_iIndex] = rsh;
		++m_iIndex;
		return true;
	}
	const MyString & operator[](int iIndex) const
	{
		return m_pData[iIndex];
	}

	int GetCount() const
	{
		return m_iIndex;
	}
	int GetArraySize() const
	{
		return m_iMaxArray;	
	}
	void InputData(const char * pTitle)
	{
		m_iIndex = 0;
		for(int i =0 ; i<GetArraySize();++i)
		{
			MyString str;
			cout<< pTitle <<  i+1 <<":";
			cin>> str;
			if(str == "")
			{
				break;
			}
			else
			{
				InsertData(str);
			}
		}
	}
	void OutputData(const char *pTitle)
	{
		for(int i= 0 ; i<GetCount(); ++i)
		{
			cout<<pTitle<<i+1<<":";
			cout<<m_pData[i]<<endl;
		}
	}
	int SearchMyString(const MyString & str)
	{
		for(int i=0 ; i<m_iIndex; ++i)
		{
			if(m_pData[i] == str)
			{
				return i;
			}
		}
		return -1;
	}
	int FindMyString(const MyString & str)
	{
		for(int i=0 ; i<m_iIndex; ++i)
		{
			if(m_pData[i].FindString(str))
			{
				return i;
			}
		}
		return -1;
	}
};
class Book
{
private: 
	MyString m_BookCode;
	MyString m_Title;
	MyString m_Pub;
	MyStringArray m_Authors;
	int m_iPrice;
	MyStringArray m_Contents;
public:
	Book():m_Authors(5),m_Contents(10)
	{

	}
	void InputData()
	{
		cout<<"Book Code: ";
		cin>>m_BookCode;
		cout<<"Title: ";
		cin>>m_Title;
		cout<<"Publisher:"; 
		cin>>m_Pub;
		
		m_Authors.InputData("Author");

		cout<<"Price: ";
		cin>>m_iPrice;
		cin.ignore(1);

		m_Contents.InputData("Contents");
	}
	void PrintData()
	{
		cout<<"Book Code: "<<m_BookCode<<endl;
		cout<<"Title: "<<m_Title<<endl;
		cout<<"Publisher: "<<m_Pub<<endl;
		
		m_Authors.OutputData("Author");
		cout<<"Price: "<<m_iPrice<<endl;
		m_Contents.OutputData("Content");
	}
	bool CompareBookCode(const MyString &BookCode)
	{
		return m_BookCode == BookCode;
	}
	bool CompareAuthor(const MyString &Author)
	{
		return m_Authors.SearchMyString(Author) != -1;
	}
	bool CompareContent(const MyString &Content)
	{
		return m_Contents.FindMyString(Content) != -1;
	}
};
class IntArray
{

private: 
	int m_iIndex;
	int m_iMaxArray;
	int *m_pData;
public:
	IntArray(int iMaxArray =10)
	{
		m_iIndex =0;
		m_iMaxArray = iMaxArray;
		m_pData = new int[m_iMaxArray];
	}
	~IntArray()
	{
		delete [] m_pData;
	}
	int GetCount() const 
	{
		return m_iIndex;
	}
	int operator [] (int iIndex)const
	{
		return m_pData[iIndex];
	}
	bool InsertData(int value)
	{
		if(m_iIndex >= m_iMaxArray)
		{
			return false;
		}
		m_pData[m_iIndex]= value;
		++m_iIndex;
		return true;
	}
};
class BookMgr
{
private: 
	Book **m_BookArray;
	int m_iIndex;
	int m_iMaxArray;
public:
	BookMgr(int iMaxArray =100)
	{
		m_iIndex =0;
		m_iMaxArray = iMaxArray;
		m_BookArray = new Book * [m_iMaxArray];
	}
	~BookMgr()
	{
		while (DeleteAt(m_iIndex-1));
	}
	void InsertBook()
	{
		if(m_iIndex >= m_iMaxArray)
		{
			cout<< "Cant insert new book"<<endl;
			return;
		}
		Book *pBook = new Book;
		pBook->InputData();
		m_BookArray[m_iIndex] = pBook;
		++m_iIndex;
	}
	void PrintAllBooks()
	{
		for(int i= 0 ; i<m_iIndex; ++i)
		{
			m_BookArray[i]->PrintData();
		}
	}
	int SearchBook(const MyString &BookCode)
	{
		for(int i =0; i<m_iIndex; ++i)
		{
			if(m_BookArray[i]->CompareBookCode(BookCode))
			{
				return i;
			}
		}
		return -1;
	}
	void Search()
	{
		MyString BookCode;
		cout<<"Code of Book to search: ";
		cin>>BookCode;
		int iSearchIndex =SearchBook(BookCode);
		if(iSearchIndex == -1)
		{
			cout<<"Can't found"<<endl;
		}
		else
		{
			m_BookArray[iSearchIndex]->PrintData();
		}
	}
	void SearchAuthor(const MyString &Author, IntArray &result)
	{
		for(int i =0 ; i<m_iIndex; ++i)
		{
			if(m_BookArray[i]->CompareAuthor(Author))
			{
				result.InsertData(i);	
			}
		}
	}
	void Printresult(IntArray &result)
	{
		for (int i = 0; i< result.GetCount(); ++i)
		{
			m_BookArray[result[i]]->PrintData();
		}
	}
	void SearchAuthor()
	{
		MyString Author;
		cout<<"Author  to search: ";
		cin>>Author;
		IntArray result(m_iIndex);
		//int iSearchIndex =SearchAuthor(Author);
		SearchAuthor(Author,result);
		if(result.GetCount() ==0)
		{
			cout<<"Can't found"<<endl;
		}
		else
		{
			Printresult(result);
		}
	}
	void SearchContent(const MyString &Content, IntArray &result)
	{
		for(int i =0 ; i<m_iIndex; ++i)
		{
			if(m_BookArray[i]->CompareContent(Content))
			{
				result.InsertData(i);	
			}
		}
	}
	void SearchContent()
	{
		MyString Content;
		cout<<"Content  to search: ";
		cin>>Content;
		IntArray result(m_iIndex);
		//int iSearchIndex =SearchAuthor(Author);
		SearchContent(Content,result);
		if(result.GetCount() ==0)
		{
			cout<<"Can't found"<<endl;
		}
		else
		{
			Printresult(result);
		}
	}

	void Modify()
	{
		MyString BookCode;
		cout<<"Code of Book to search: ";
		cin>>BookCode;
		int iSearchIndex =SearchBook(BookCode);
		if(iSearchIndex == -1)
		{
			cout<<"Can't found"<<endl;
		}
		else
		{
			m_BookArray[iSearchIndex]->InputData();
		}
	}
	bool DeleteAt(int iSearchIndex)
	{
		if(m_iIndex ==0)
		{
			return false;
		}
		memcpy(&m_BookArray[iSearchIndex],&m_BookArray[iSearchIndex+1], sizeof(Book*)*(m_iIndex-iSearchIndex-1));
		--m_iIndex;
		return true;
	}
	void Delete()
	{
		MyString BookCode;
		cout<<"Code of Book to search: ";
		cin>>BookCode;
		int iSearchIndex =SearchBook(BookCode);
		if(iSearchIndex == -1)
		{
			cout<<"Can't found"<<endl;
		}
		else
		{
			DeleteAt(iSearchIndex);
		}
	}
	void Menu()
	{
		int iChoice =1;
		while(iChoice !=0)
		{
			cout<<"1. InsertBook"<<endl;
			cout<<"2. PrintAll"<<endl;
			cout<<"3. Search"<<endl;
			cout<<"4. Search Author"<<endl;
			cout<<"5. Search Content"<<endl;
			cout<<"6. Modify"<<endl;
			cout<<"7. Delete"<<endl;
			cin>>iChoice;
			cin.ignore(1);
			switch(iChoice)
			{
			case 1 :
				InsertBook();
				break;
			case  2:
				PrintAllBooks();
				break;
			case 3: 
				Search();
				break;
			case 4:
				SearchAuthor();
				break;
			case 5: 
				SearchContent();
				break;
			case 6: 
				Modify();
				break;
			case 7: 
				Delete();
				break;
			}
		}
	}
};
void main()
{
	BookMgr b1;
	b1.Menu();
}
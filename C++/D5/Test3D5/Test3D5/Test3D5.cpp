#include <iostream>
using namespace std;
#include "MyString.h"

namespace video
{
	class Member
	{
	public:
		void Input()
		{
			cout<<"video" <<endl;
			cout<<"Name:";
			cin>>m_Name;
			cout<<"Add: ";
			cin>>m_Addr;

			cout<<"tel: ";
			cin>>m_tel;
		}
		void Print() const
		{
			cout<<"name:"<<m_Name<<endl;
			cout<<"add:"<<m_Addr<<endl;
			cout<<"tel:"<<m_tel<<endl;

		}
	private:
		MyString m_Name;
		MyString m_Addr;
		MyString m_tel;
	};
}
namespace cafe
{
	class Member
	{
	public:
		void Input()
		{
			cout<<"Cafe"<<endl;
			cout<<"Name:";
			cin>>m_Name;
			cout<<"Add: ";
			cin>>m_Addr;

			cout<<"tel: ";
			cin>>m_tel;
		}
		void Print() const
		{
			cout<<"name:"<<m_Name<<endl;
			cout<<"add:"<<m_Addr<<endl;
			cout<<"tel:"<<m_tel<<endl;

		}
	private:
		MyString m_Name;
		MyString m_Addr;
		MyString m_tel;
	};
}
//class Member
//{
//public:
//	void Input()
//	{
//		cout<<"Name:";
//		cin>>m_Name;
//		cout<<"Add: ";
//		cin>>m_Addr;
//
//		cout<<"tel: ";
//		cin>>m_tel;
//	}
//	void Print() const
//	{
//		cout<<"name:"<<m_Name<<endl;
//		cout<<"add:"<<m_Addr<<endl;
//		cout<<"tel:"<<m_tel<<endl;
//
//	}
//private:
//	MyString m_Name;
//	MyString m_Addr;
//	MyString m_tel;
//};
using namespace video;
void main()
{
	Member m1;
	m1.Input();
	m1.Print();
	cafe::Member m2;
	m2.Input();
	m2.Print();
}
#include <iostream>
using namespace std;

class Cat
{
public: 
	/*Cat ()
	{
	cout<<"cat (int iage=0)"<<endl;
	m_iage = 0;
	}*/
	Cat (int iage=0)
	{
		cout<<"cat (int iage=0)"<<endl;
		m_iage = iage;
	}
	Cat (Cat & rsh)
	{
		cout<<"cat (Cat & rsh)"<<endl;
		m_iage = rsh.m_iage;
	}
	void setage(int iAge)
	{
		m_iage = iAge;
	}
	int getage() const
	{
		return m_iage;
	}
private: 
	int m_iage;
};

void main()
{
	Cat c1(10);
	Cat c2(c1);
	cout<<"c1.getage():"<<c1.getage()<<endl;
	cout<<"c2.getage():"<<c2.getage()<<endl;
}
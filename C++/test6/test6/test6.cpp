#include<iostream>
using namespace std;

class cat
{
public:
	cat()
	{
		cout<<"cat()"<<endl;
		m_iage = 0;
	}
	cat(int iage)
	{
		cout<<"cat(int iage)"<<endl;
	}
	int getage() const
	{
		return m_iage;
	}
	void setage(int iage)
	{
		m_iage = iage;
	}
	~cat()
	{

	}
private: 
	int m_iage;
};
void main()
{
	cat c1;
}
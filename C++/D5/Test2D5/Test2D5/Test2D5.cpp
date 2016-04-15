#include <iostream>
using namespace std;

class cat
{
public:
	/*cat(int iAge=0): m_iAge(iAge)
	{
	cout<<"Cat(int iAge=0)"<<endl;
	}*/
	~cat()
	{
		cout<<"~Cat()"<<endl;
		--m_iCatCount;
	}
	int GetAge() const
	{
		return m_iAge;
	}
	void setage(int iAge)
	{
		m_iAge= iAge;
	}
	static cat* createobject() 
	{
		if(m_iCatCount < 5)
			return new cat;
		else
		{
			return NULL;
		}
	}
private:
	int m_iAge;
	static int m_iCatCount;
	cat(int iAge=0): m_iAge(iAge)
	{
		cout<<"Cat(int iAge=0)"<<endl;
		++m_iCatCount;
	}
};
int cat::m_iCatCount =0;

class catsmartpointer
{
public:
	catsmartpointer()
	{
		m_pcat = cat::createobject();
	}
	~catsmartpointer()
	{
		delete m_pcat;
	}
	cat * operator->()
	{
		return m_pcat;
	}
private:
	cat * m_pcat;
};
void main()
{
	catsmartpointer c1;
	c1->setage(10);
	cout<<c1->GetAge()<<endl;
	catsmartpointer c2;
	catsmartpointer c3;
	catsmartpointer c4;
	catsmartpointer c5;
	catsmartpointer c6;
	//cat *pcat1 =  cat::createobject();
	//cat *pcat2 =  cat::createobject();
	//cat *pcat3 =  cat::createobject();
	//cat *pcat4 =  cat::createobject();
	//cat *pcat5 =  cat::createobject();
	//cat *pcat6 =  cat::createobject();
	//
	//delete pcat1;
	//delete pcat2;
	//delete pcat3;
	//delete pcat4;
	//delete pcat5;
	//delete pcat6;

}
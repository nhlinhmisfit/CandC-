#include <iostream>
using namespace std;


//int & MyFunc(int *pInt)
//{
//	return *pInt;
//}
//void main()
//{
//	int ivalue = 10;
//	int & r = MyFunc(&ivalue);
//	cout<<"ivalue: "<<ivalue <<endl;
//}

class counter
{
public:
	~counter()
	{
		cout<<"~counter()"<<endl;
	}
	counter(const counter &rsh)
	{
		cout<<"counter(const counter &rsh)"<<endl;
		m_icount = rsh.m_icount;
	}
	counter(int icount=0)
	{
		cout<<"counter(int icount=0)"<<endl;
		m_icount = icount;
	}
	void Increment()
	{
		++m_icount;
	}
	int GetCountValue()
	{
		return m_icount;
	}
	counter & operator++()
	{
		cout<<"counter & operator++()"<<endl;
		++this->m_icount;
		//counter temp(m_icount);
		return *this;
	}
	counter  operator++(int )
	{
		cout<<"counter  operator++(int )"<<endl;
		int icount = m_icount;
		++this->m_icount;
		return icount;
	}
	//counter operator++()
	//{
	//	++m_icount;
	//	//counter temp(m_icount);
	//	return m_icount;
	//	counter Imsi = m_icount;
	//}
private:
	int m_icount;
};
void main()
{

	counter c1(10);
	counter c2;
	cout<<"c1.getcountervalue(): "<< c1.GetCountValue()<<endl;
	cout<<"c2.getcountervalue(): "<< c2.GetCountValue()<<endl;
	//c1.Increment();
	//c1.operator++();
	cout<<"============================="<<endl;
	c2 = c1++;
	//c2 = c1.operator++();
	cout<<"============================="<<endl;
//	c2 = c1.operator++();
	cout<<"c1.getcountervalue(): "<< c1.GetCountValue()<<endl;
	cout<<"c2.getcountervalue(): "<< c2.GetCountValue()<<endl;
}
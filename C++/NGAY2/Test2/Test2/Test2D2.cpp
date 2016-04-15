#include <iostream>
using namespace  std;

class counter
{
private:
	int m_iCount;
public:
	counter(int iCount = 0):m_iCount(iCount)
	{
		cout<<"counter(int iCount = 0)"<<endl;
		//m_iCount = iCount;
	}
	~counter()
	{
		cout<<"~counter()"<<endl;
	}
	counter(const counter &rsh): m_iCount(rsh.m_iCount)
	{
		cout<<"counter(const counter &rsh)"<<endl;
	}
	int GetCountValue() const
	{
		return m_iCount;
	}
	void Increment()
	{
		++m_iCount;
	}
	counter & operator ++() // reference co 2 truong hop, 1: cos parameter 2: khong co parameter
		//counter *const this 
	{
		++m_iCount;
		return *this;
	}
	counter  operator ++(int)
		//counter *const this 
	{
		int iCount = m_iCount;
		++m_iCount;
		return iCount;
	}
	counter  operator+(const counter & rsh)
		//counter *const this
	{
		return this->m_iCount +rsh.m_iCount;

	}	
	counter & operator+=(const counter &rsh)
	{
		this->m_iCount += rsh.m_iCount;
		return *this;
	}
	bool operator==(const counter &rsh)
	{
		return m_iCount == rsh. m_iCount;
	}
	bool operator!=(const counter &rsh)
	{
		return !(*this==rsh); //quan trong
	}
	bool operator>(const counter &rsh)
	{
		return m_iCount > rsh. m_iCount;
	}
	bool operator<=(const counter &rsh)
	{
		return !(*this >rsh);
	}
	bool operator<(const counter &rsh)
	{
		return m_iCount < rsh. m_iCount;
	}
	bool operator>=(const counter &rsh)
	{
		return !(*this < rsh);
	}
};
counter operator+(int iCount, const counter &rsh)
{
	return iCount +rsh.GetCountValue();
}
void main()
{

	//counter c1; 
	//cout<<"c1.Getcounvalue(): "<<c1.GetCountValue()<<endl;
	//c1.Increment();
	//++c1; // c1.operator++();
	//cout<<"c1.Getcounvalue(): "<<c1.GetCountValue()<<endl;
	
	counter c1(10);
	counter c2(20);
	counter c3;
	cout<<"c1.GetCountValue():"<<c1.GetCountValue()<<endl;
	cout<<"c2.GetCountValue():"<<c2.GetCountValue()<<endl;
	cout<<"c3.GetCountValue():"<<c3.GetCountValue()<<endl;

	cout<<"=================="<<endl;
	//c3 = c1 + c2; // c3= c1.operator+(c2) //ko hieu qua
	//c3 = c1 +=c2; //c3 = c1.operator+=(c2) // co hieu qua hon
	//c3= 40 +c1;
	if(c1 != c2)
	{
		cout<<"c1 != c2"<<endl;
	}
	else
	{
		cout<<"c1 ==c2"<<endl;
	}

	cout<<"=================="<<endl;

	cout<<"c1.GetCountValue():"<<c1.GetCountValue()<<endl;
	cout<<"c2.GetCountValue():"<<c2.GetCountValue()<<endl;
	cout<<"c3.GetCountValue():"<<c3.GetCountValue()<<endl;
}
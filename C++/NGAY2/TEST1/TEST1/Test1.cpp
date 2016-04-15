#include <iostream>
using namespace std;

class cat 
{
private: 
	int m_iAge;
public:
	cat()
	{
		cout<<"Cat()"<<endl;
		m_iAge = 0;
	}
	cat(int iAge)//cat *const this
	{
		cout<<"Cat(int iAge)"<<endl;
		m_iAge = iAge;
	}
	~cat()
	{
		cout<<"~cat()"<<endl;
	}
	cat(const cat & rsh)
	{
		cout<<"cat(const cat & rsh)"<<endl;
		this->m_iAge = rsh.m_iAge;
	}
	void SetAge(int iAge) //cat *const this, int iAge
	{
		m_iAge = iAge;
	}
	int GetAge()const //const cat *const this
	{
		return m_iAge;
	}
};
//void setAge(int iAge)
//	// Cat * const this, int iAge
//	// ham ko co const chay dc ham co const
//{
//	// getAge(); not cause error
//	// this->getAge();
//	// getAge(this);
//	m_iAge = iAge;
//}
//int getAge() const
//	//ham co const ko the chay ham ko co const
//	//const Cat * const this
//{
//	//setAge(10) cause error
//	return m_iAge;
//}
void main()
{
	// int i(10);
	//int i = 10;
	//cout<<"i : "<< i <<endl;
	cat c1(20);//cat(&c1,20) // cat c1 = 20; // int i = 10;
	cat c2 =c1; // cat c2(c1)// cat(&c2,c1)
	
	cout<<"c1.GetAge(): "<<c1.GetAge()<<endl;
	cout<<"c2.GetAge(): "<<c2.GetAge()<<endl;

}
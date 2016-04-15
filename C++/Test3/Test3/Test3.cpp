#include <iostream>
using namespace std;

class Cat
{
private:
	int m_iAge;
public: 
	//Cat ()
	//{
	//	cout<<"Cat()"<<endl;
	//	m_iAge = 0;
	//}
	Cat(int iAge =0)
	{
		cout<<"Cat(int iAge)"<<endl;
		m_iAge =iAge;
	}
	void setage(int iAge)
	{
		//cat * const this, int iAge

		if(iAge <0)
		{
			cout<<"can't write value "<<endl;
			return;
		}
		
		this->m_iAge = iAge;
	}
	int getage() const 
	{
		//this->m_iAge =20;
		return m_iAge;
	}
};


void main()
{
	Cat c1;
	//c1.setage(10);
	cout<<c1.getage()<<endl;
}



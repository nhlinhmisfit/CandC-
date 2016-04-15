#include <iostream>
using namespace std;



class cat
{
private:
	int m_iAge;
	static int m_iCatCount ;
public:
	cat(int iAge =0):m_iAge(iAge)
	{
		cout<<"Cat(int iAge=0)"<<endl;
		++m_iCatCount;
	}
	~cat()
	{
		cout<<"~cat()"<<endl;
		--m_iCatCount;
	}
	int GetAge() const 
	{
		return m_iAge;
	}
	void SetAge(int iAge)
	{
		m_iAge = iAge;
	}
	static int GetCount() // static k co this ne khong the chay setage(10)
						//this->setage(10) setage(this,10)
	{
		return m_iCatCount;
	}
};

//richard branson
//charles simonyi
// matrix
int cat::m_iCatCount =0;
void main()
{
	//cat::m_iCatCount =10;
	cout<< "sizeof(cat): " <<sizeof(cat)<<endl;
	{
		cout<<"iCatCount: "<< cat::GetCount()<<endl;
		{
			cat c1; 
			cout<<"iCatCount: "<<cat::GetCount()<<endl;
			cout<<"&c1: "<<&c1<<endl;
			cout<<"&iCatCount: "<<cat::GetCount()<<endl;
			{
				cat c2; 
				cout<<"iCatCount: "<<cat::GetCount()<<endl;
				{
					cat c3; 
					cout<<"iCatCount: "<<cat::GetCount()<<endl;
					{
						cat c4; 
						cout<<"iCatCount: "<<cat::GetCount()<<endl;
					}
					cout<<"iCatCount: "<<cat::GetCount()<<endl;
				}
				cout<<"iCatCount: "<<cat::GetCount()<<endl;
			}
			cout<<"iCatCount: "<<cat::GetCount()<<endl;
		}
		cout<<"iCatCount: "<<cat::GetCount()<<endl;
	}
}
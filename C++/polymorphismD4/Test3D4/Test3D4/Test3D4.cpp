#include <iostream>
using namespace std;

class Wing
{
public:
	void Fly() const 
	{
		cout<<"Fly"<<endl;
	}
};

class Bird 
{
private: 
	Wing m_Wing;
public:
	
	void Speak() const
	{
		cout<<"ZZack!!!!, ZZack!!!"<<endl;
	}
	void GiveEgg() const
	{
		cout<<"Give Egg"<<endl;
	}
	int m_iAge[100];

	void Fly()const
	{
		m_Wing.Fly();
	}
};

class Pegasus
{
private:
	int m_iAge;
	 Wing m_wing;
public: 
	Pegasus(int iAge = 0): m_iAge(iAge)
	{

	}
	int GetAge() const
	{
		return m_iAge;
	}
	void SetAge(int iAge)
	{
		m_iAge = iAge;
	}
	void Gallop() const
	{
		cout<<"Gallop!!!"<<endl;
	}
	void Speak() const
	{
		cout<<"Heeing!!!!,Heeing!!!"<<endl;
	}
	void Fly() const
	{
		m_wing.Fly();
	}
	void GiveEgg() const
	{
		cout<<"i can't Give Egg"<<endl;
	}
};

void main()
{
	Pegasus p;
	cout<< sizeof(p)<<endl;
	p.Gallop();
	p.Fly();
	p.Speak();
	//p.GiveEgg();

}
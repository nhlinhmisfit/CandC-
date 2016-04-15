#include <iostream>
using namespace std;

class Bird
{
public:
	void Fly() const 
	{
		cout<<"Fly"<<endl;
	}
	void Speak() const
	{
		cout<<"ZZack!!!!, ZZack!!!"<<endl;
	}
	void GiveEgg() const
	{
		cout<<"Give Egg"<<endl;
	}
};
class Pegasus : public Bird
{
private:
	int m_iAge;
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
	void GiveEgg() const
	{
		cout<<"i can't Give Egg"<<endl;
	}
};

void main()
{
	Pegasus p;
	p.Gallop();
	p.Fly();
	p.Speak();
	p.GiveEgg();

}
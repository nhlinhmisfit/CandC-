#include <iostream>
using namespace std;

class  Animal
{
public:
	Animal(): m_iWeight(0)
	{
		cout<<"Animal()"<<endl;
	}
	Animal(int iWeight): m_iWeight(iWeight)
	{
		cout<<"Animal(int iWeight)"<<endl;
	}
	~Animal()
	{
		cout<<"~Animal"<<endl;
	}
	Animal(const Animal &rsh)
	{
		cout<<"Animal(const Animal &rsh) "<<endl;
		m_iWeight = rsh.m_iWeight;
	}
	int GetWeight() const
	{
		return m_iWeight;
	}
	void SetWeight(int iWeight)
	{
		m_iWeight = iWeight;
	}
	Animal & operator=(const Animal & r)
	{
		cout<<"Animal & operator=(const Animal & r)"<<endl;
		if(this == &r)
		{
			return *this;
		}
		m_iWeight =  r.m_iWeight;
		return *this;
	}
private:
	int m_iWeight;
};
class  cat :public Animal
{
public:
	cat(): m_iAge(0)
	{
		cout<<"cat()"<<endl;
	}
	cat(int iAge): Animal(10),m_iAge(iAge)
	{
		cout<<"cat(int iiAge)"<<endl;
	}
	~cat()
	{
		cout<<"~cat"<<endl;
	}
	cat (const cat &rsh) : Animal(rsh)
	{
		cout<<"cat (const cat &rsh):"<<endl;
		m_iAge = rsh.m_iAge;
	}
	int GetAge() const
	{
		return m_iAge;
	}
	void SetAge(int iAge)
	{
		m_iAge = iAge;
	}
	cat & operator=(const cat & r)
	{
		Animal :: operator=(r);
		cout<< "cat & operator=(const cat & r)"<<endl;
		if(this == &r)
			return *this;
		m_iAge = r.m_iAge;
		return *this;
	}
private:
	int m_iAge;
};
void main()
{
	//Animal a;
	cat c1;
	c1.SetAge(10);
	c1.SetWeight(20);
	cout<<"c1.SetAge(): "<<c1.GetAge()<<endl;
	cout<<"c1.GetWeight(): "<<c1.GetWeight()<<endl;

	cat c2;
	cout<<"c2.SetAge(): "<<c2.GetAge()<<endl;
	cout<<"c2.GetWeight(): "<<c2.GetWeight()<<endl;
	c2 = c1;
	cout<<"c2.SetAge(): "<<c2.GetAge()<<endl;
	cout<<"c2.GetWeight(): "<<c2.GetWeight()<<endl;
}
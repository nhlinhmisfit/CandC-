#include <iostream>
using namespace std;

class Animal
{
private:
	int m_iWeight;
public:
	Animal()
	{
		cout<<"Animal()"<<endl;
		m_iWeight = 0;
	}
	Animal(int iWeight)
	{
		cout<<"Animal(int iWeight)"<<endl;
		m_iWeight= iWeight;
	}
	~Animal()
	{
		cout<<"~Animal()"<<endl;
	}
	void SetWeight(int iWeight)
	{
		m_iWeight =iWeight;
	}
	int GetWeight()const 
	{
		return m_iWeight;
	}
	void Speak()const
	{
		cout<<"animal speak!!!!"<<endl;
	}
};
class cat : public Animal
{
public:
	cat()
	{
		cout<<"cat()"<<endl;
	}
	cat(int iAge): m_iAge(iAge)
	{
		cout<<"cat(int iAge)"<<endl;
	}
	~cat()
	{
		cout<<"~cat()"<<endl;
	}
	int GetAge()const
	{
		return m_iAge;
	}
	void SetAge(int iAge)
	{
		m_iAge = iAge;
	}
	void Speak() const
	{
		cout<<"Meow!!!!"<<endl;
	}
private:
	int m_iAge;
};
void main()
{
	cat c1;
	cout<<"size: "<<sizeof(c1)<<endl;
	c1.SetAge(10);
	cout<< c1.GetAge()<<endl;
	c1.SetWeight(20);
	cout<< c1.GetWeight()<<endl;
	c1.Speak();

	Animal *pAnimal = &c1;
	pAnimal ->Speak();

	Animal &rAnimal = c1;
}
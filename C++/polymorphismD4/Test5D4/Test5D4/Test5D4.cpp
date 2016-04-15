#include <iostream>
using namespace  std;
class Animal2
{
public: 
	Animal2(int iAge =0): m_iAge(iAge)
	{
		cout<<"Animal(int iAge =0): m_iAge(iAge)"<<endl;
	}
	virtual ~Animal2()
	{
		cout<<"~Animal()"<<endl;
	}
	virtual void Speak2() const
	{
		cout<< "Animal Speak2!!!"<<endl;
	}
	virtual void S() const
	{
		cout<< "Animal Speak!!!"<<endl;
	}
private:
	int m_iAge;
};
class Animal
{
public: 
	Animal(int iAge =0): m_iAge(iAge)
	{
		cout<<"Animal(int iAge =0): m_iAge(iAge)"<<endl;
	}
	virtual ~Animal()
	{
		cout<<"~Animal()"<<endl;
	}
	virtual void Speak() const
	{
		cout<< "Animal Speak!!!"<<endl;
	}
	virtual void Speak2() const
	{
		cout<< "Animal Speak2!!!"<<endl;
	}
private:
	int m_iAge;
};
class cat :public Animal
{
public:
	cat()
	{
		cout<<"cat()"<<endl;
	}
	~cat()
	{
		cout<<"~cat()"<<endl;
	}
	void Speak() const
	{
		cout<<"Meow!!!"<<endl;
	}
	void Speak2() const
	{
		cout<<"Meow2!!!"<<endl;
	}
};
class dog :public Animal

{
public:
	dog()
	{
		cout<<"dog()"<<endl;
	}
	~dog()
	{
		cout<<"~dog()"<<endl;
	}
	void Speak() const
	{
		cout<<"Warf!!!, Warf!!!"<<endl;
	}
	void Speak2() const
	{
		cout<<"Warf2!!!, Warf2!!!"<<endl;
	}
};
class pig :public Animal
{
public:
	pig()
	{
		cout<<"pig()"<<endl;
	}
	~pig()
	{
		cout<<"~pig()"<<endl;
	}
	void Speak() const
	{
		cout<<"pig!!!, pig!!!"<<endl;
	}
	void Speak2() const
	{
		cout<<"pig2!!!, pig2!!!"<<endl;
	}
};

void main() // virtual function table pointer 
{
	//Animal * pAnimal[5];
	//for(int i = 0 ; i<5 ; ++i)
	//{
	//	cout<<"1. Cat"<< endl;
	//	cout<<"2. Dog"<< endl;
	//	cout<<"3. Pig"<< endl;
	//	int ichoice;
	//	cin>> ichoice; cin.ignore(1);
	//	switch(ichoice)
	//	{
	//	case 1 :
	//		pAnimal[i] = new cat;
	//		break;
	//	case 2: 
	//		pAnimal[i] = new dog; break;
	//	case 3:
	//		pAnimal[i] = new pig;
	//		break;
	//	}
	//}
	//for(int i = 0 ; i< 5 ; ++i) 
	//{
	//	pAnimal[i]->Speak();
	//}
	////pAnimal[0] ->Speak();
	//for(int i = 0 ; i< 5 ; ++i) 
	//{
	//	delete  pAnimal[i];
	//}

	cat *pCat = new cat ;
	Animal *pAnimal = pCat;
	pAnimal ->Speak();
	pAnimal ->Speak2();

	Animal2 *pAnimal2 = (Animal2 *) pCat;
	pAnimal2 ->S();

}
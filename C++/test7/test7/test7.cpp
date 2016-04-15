#include <iostream>
using namespace std;

class member
{
public:
	 member()
	 {
	 }
	~member()
	{
		cout<<"~member()"<<endl;
		delete [] m_name;
		delete []m_num;
		delete []m_addr;
	}
	void Input()
	{
		char temp[1024];
		cout<<"name: ";
		cin.getline(temp,sizeof(temp));
		m_name = new char[strlen(temp)+1];
		strcpy(m_name,temp);

		cout<<"addr: ";
		cin.getline(temp,sizeof(temp));
		m_addr =  new char[strlen(temp)+1];
		strcpy(m_addr,temp);

		cout<<"tel_num: ";
		cin.getline(temp,sizeof(temp));
		m_num =  new char[strlen(temp)+1];
		strcpy(m_num,temp);
	}
	void Print()
	{
		cout<<"name: "<<m_name<<endl;
		cout<<"addr: "<<m_addr<<endl;
		cout<<"tel_num: "<<m_num<<endl;
	}
	member(const member & rsh)
	{
		m_name = new char[strlen(rsh.m_name)+1];
		strcpy(m_name,rsh.m_name);
		m_addr = new char[strlen(rsh.m_addr)+1];
		strcpy(m_addr,rsh.m_addr);
		m_num = new char[strlen(rsh.m_num)+1];
		strcpy(m_num,rsh.m_num);
	}
private:
	char *m_name;
	char *m_addr;
	char *m_num;
};

class cat
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
private: 
	

};
void main()
{
	/*int *pInt = new int;
	*pInt = 10;
	delete pInt;*/


	member m1;
	m1.Input();
	m1.Print();

	member m2(m1);
	m2.Print();

	//cat *pcat= new cat[10];

	//delete []pcat;

}
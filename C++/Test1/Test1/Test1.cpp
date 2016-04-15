
#include <iostream>
using namespace std;

void MyFunc()
{
	cout<<"void MyFunc()" <<endl;
}
void MyFunc(int x)
{
	cout<<"void MyFunc(int x)"<<endl;
}
void MyFunc(float x)
{
	cout<<"void MyFunc(float x)"<<endl; 
}

void main()
{
	MyFunc();
	MyFunc(10);
	MyFunc(10.5f);
	//MyFunc(10.5f);
}

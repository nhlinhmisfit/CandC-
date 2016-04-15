#include <iostream>
using namespace std;

//void MySwap(int *x, int *y)
//{
//	int temp =*x;
//	*x =*y;
//	*y =temp;
//}
//
//void main()
//{
//	int i = 10;
//	int j =20;
//	cout<<"i: "<< i <<",j "<<j <<endl;
//	MySwap(&i,&j);
//	cout<<"i: "<<i <<",j: "<< j <<endl;
//}
void swap(int  & rx, int & ry)
{
	int temp = rx;
	rx= ry;
	ry =temp;
}
void main()
{
	/*int i = 10 ; 
	int & ri = i;
	cout << "i : "<< i <<endl;
	cout << "&i : "<< &i <<endl;
	cout << "ri : "<< ri <<endl;
	cout << "&ri : "<< &ri <<endl;*/
	int i = 10; 
	int j =20;
	cout <<"i: " <<i << ", j "<< j<<endl;
	swap(i,j);
	cout <<"i: " <<i << ", j "<< j<<endl;

}
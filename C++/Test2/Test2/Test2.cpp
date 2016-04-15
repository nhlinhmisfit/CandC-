#include <iostream>
using namespace std;

inline int MAX(int x, int y)
{
	return (x>y? x:y);
}
void main()
{
	int x =10;
	int y =20;
	int iMax = MAX(x,y);
	cout<<"x:"<< x <<endl;
	cout<<"y: "<< y <<endl;
	cout<<"imax: "<<iMax<<endl;
}

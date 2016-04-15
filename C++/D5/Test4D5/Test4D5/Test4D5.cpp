#include <iostream>
using namespace std;

template <class T>
void Swap(T &rx, T &ry) //'generic programe
{
	T temp = rx;
	rx =ry;
	ry =temp;
}
//void Swap(int &rx, int &ry)
//{
//	int temp = rx;
//	rx= ry;
//	ry= temp;
//}
//void Swap(float &rx, float &ry)
//{
//	float temp = rx;
//	rx= ry;
//	ry= temp;
//}
//void Swap(double &rx, double &ry)
//{
//
//	double	temp = rx;
//	rx= ry;
//	ry= temp;
//}
void main()
{
	int x =10;
	int y =20;
	cout<<"x: "<<x<< ",y:"<<y<<endl;
	Swap(x,y);
	cout<<"x: "<<x<< ",y:"<<y<<endl;

	float fx =10.5f;
	float fy =20.5f;
	cout<<"fx: "<<fx<< ",fy:"<<fy<<endl;
	Swap(fx,fy);
	cout<<"fx: "<<fx<< ",fy:"<<fy<<endl;

	double dx =10.5f;
	double dy =20.5f;
	cout<<"dx: "<<dx<< ",dy:"<<dy<<endl;
	Swap(dx,dy);
	cout<<"dx: "<<dx<< ",dy:"<<dy<<endl;
	
}
#include <stdio.h>
#include <malloc.h>

void MyFunc(int * p)
{
	*p=10;
}
void main()
{
	int *p = (int * ) malloc(4);
	/*int * const p= (int * ) malloc(4);
	const 	int * const p= (int * ) malloc(4);*/
	MyFunc(p);
	//*p = 10;
	//++p;

}
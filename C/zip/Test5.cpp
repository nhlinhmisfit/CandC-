#include<stdio.h>
#include <Windows.h>

void DispStar()
{
	printf("*");
}
void DispArrow()
{
	printf("->");
}

typedef void (* DISPFUNC)();

int MyFunc(DISPFUNC DispFunc)
{
	int sum =0;
	for (int i= 0 ; i< 10; ++i)
	{
		sum +=i;
		DispFunc();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
		Sleep(1000);
	}
	return sum;
}
void main()
{
	///*void ( * p)() = MyFunc;*/
	//FUNCPTR p = MyFunc;
	//printf("MyFunc : %p\n", MyFunc);
	//printf("p : %p\n",p);
	///*int *p = (int * )main;
	//*p =10;
	//printf("Myfunc : %p\n", main);*/
	//MyFunc();
	//p();

	int iResult = MyFunc(DispArrow);
	printf("iResult : %d\n", iResult);
}


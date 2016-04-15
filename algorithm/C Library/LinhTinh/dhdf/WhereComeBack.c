#include <stdio.h>

int Func_B(int arg){
	if(arg){
		printf("Func A have %d	\n", arg);
		printf("	Return to Function with [%d]\n", arg);
	}
	return 0;
}

int Func_A(int arg){
	if(arg){
		printf("Func A have %d	\n", arg);
		Func_B(arg-1);
		printf("	Return to Function with [%d]\n", arg);
	}
	return 0;
}
int main( void ){
	int number = 10;
	printf("Start Main Function \n");
	Func_A(number);
	printf("End Main Function \n");

	return 0;
}
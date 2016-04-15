#include <stdio.h>


void main()
{
	/*int x;
	int y;
	int iResult;*/
	int * pi;
	int i;
	i = 10;
	pi = &i;

	printf("pi: %p\n", pi);  //
	printf("&pi: %p\n\n", &pi);

	printf("i: %p\n", i);
	printf("&i: %p\n\n", &i);


	printf("*pi: %d\n", *pi);


	/*printf("&x : %p\n", &x);
	printf("&y : %p\n", &y);
	printf("&i : %p\n", &iResult);*/

	/*x =10;
	y = 20;
	iResult = x+y;

	printf("&x : %p\n", &x);
	printf("&y : %p\n", &y);
	printf("&i : %p\n", &iResult);*/

	//printf("x : %d\n", x);
	//printf("y : %d\n", y);
	//printf("i : %d\n", iResult);

	/*printf("%d + %d = %d\n", x,y,iResult);*/


}
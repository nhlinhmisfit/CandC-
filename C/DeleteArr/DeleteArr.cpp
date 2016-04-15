#include<stdio.h>
#include <memory.h>
#include <conio.h>

typedef void (* MENUFUNC)();

typedef struct _MENUINTEM
{
	MENUFUNC MenuFunc;
	const char *MenuTitle;
}MENUINTEM;
void Input()
{
	printf("Input print\n");
}
void main()
{
	MENUINTEM MenuIntem[] = {
		Input, "Input",

	};
}
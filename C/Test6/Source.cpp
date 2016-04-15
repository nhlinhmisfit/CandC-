
#include <conio.h>
#include <memory.h>
#include <stdio.h>
	//Late Binding
	void Input()
{
	printf("Input\n");
}
void Print()
{
	printf("Print\n");
}
void Search()
{
	printf("Search\n");
}
void Modify()
{
	printf("Modify\n");
}
void Delete()
{
	printf("Delete\n");
}

typedef void (* MENUFUNC)();

typedef struct _MENUITEM
{
	MENUFUNC MenuFunc;
	const char * Menutitle;
}MENUITEM;//8 bytes
void main()	
{
	MENUITEM MenuItem[]= {
		Input,"Input",
		Print,"Print",
		Search,"Search",
		Modify,"Modify",
		Delete,"Delete",
	};
	int iMenuItemSize = sizeof(MenuItem)/sizeof(MenuItem[0]);
	int iChoice =1;
	//Insert using buffer
	MENUITEM MenuItemBuffer[5];
	int iBufferItem =0;
	while(iChoice!=0)
	{
		int i =0;
		for(;i<iMenuItemSize;++i)
		{
			printf("%d.%s\n",i+1,MenuItem[i].Menutitle);
		}
		printf("%d.DeleteMenu\n",i+1);//Early Binding
		printf("%d.InsertMenu\n",i+2);
		scanf("%d",&iChoice);
		if(iChoice >0 && iChoice<= iMenuItemSize)
		{
			MenuItem[iChoice-1].MenuFunc();//Late Binding
		}else if(iChoice == iMenuItemSize+1)
		{
			memcpy(&MenuItemBuffer[iBufferItem],&MenuItem[0],sizeof(MenuItem[0]));
			memcpy(&MenuItem[0],&MenuItem[1],sizeof(MenuItem[0])*(iMenuItemSize-1));
			++iBufferItem;
			--iMenuItemSize;
		}else if (iChoice == iMenuItemSize+2)
		{
			if(iBufferItem ==0){
				printf("No Item in Delete Buffer\n");
			}else
			{
				memcpy(&MenuItem[iMenuItemSize],&MenuItemBuffer[0],sizeof(MenuItem[0]));
				memcpy(&MenuItem[0],&MenuItemBuffer[1],sizeof(MenuItemBuffer[0])*(iBufferItem-1));
				--iBufferItem;
				++iMenuItemSize;
			}
		}
	}
}
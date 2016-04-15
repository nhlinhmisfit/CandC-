//#include <stdio.h>
//#include <memory.h>
//void input ()
//{
//	printf("Input\n");
//}
//void Print()
//{
//	printf("Print\n");
//}
//void Search()
//{
//	printf("Search\n");
//}
//void Modify()
//{
//	printf("Modify\n");
//}
//void Delete()
//{
//	printf("Delete\n");
//}
//typedef void (* MENUFUNC)();
//
//typedef struct _MENUITEM
//{
//	MENUFUNC MenuFunc;
//	const char * MenuTitle;
//}MENUINTEM;
//
//void main()
//{
//	MENUINTEM MenuItem[5] = {
//		input, "Input",
//		Print,"Print",
//		Search, "Search",
//		Modify, "Modify",
//		Delete, "Delete",
//	};
//	int iMenuItemSize =
//		sizeof(MenuItem)/sizeof(MenuItem[0]);
//
//	int iChoice =1;
//	while(iChoice != 0)
//	{
//		int i=0;
//		for ( ; i < iMenuItemSize ; ++i)
//		{
//			printf("%d.%s\n", i+1,MenuItem[i].MenuTitle);
//		}
//		printf("%d.DeleleMenu",i+1);             //early binding 
//
//		scanf("%d", &iChoice);
//		if(iChoice >0 && iChoice <= iMenuItemSize)
//		{
//			MenuItem[iChoice-1].MenuFunc();      //lately binding
//		}
//		else if(iChoice == iMenuItemSize +1)
//		{
//			memcpy(&MenuItem[0], &MenuItem[1],sizeof(MenuItem[0])*(iMenuItemSize -1));
//			--iMenuItemSize;
//		}
//	}
//}
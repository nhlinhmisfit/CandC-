//#include <stdio.h>
//#include <stdlib.h>
///*
//	looks like loop 
//	do not use when too many data 
//	have limit about  4000 times x int type
//	Virtual Memory menagement default size / 1 application
//	general use sorting, searching, 
//	Tree, Graph 
//	if you cannot use recursive call
//	very important
//	basic template 
//	recursive_call_func()
//	{
//		if(when stop(loop))
//		{
//		must have this line
//		}
//		preprocess;	
//		recursive_call();
//		post process;
//	}
//*/
//int ar[10][10] =
//{
//	{1,0,0,0,0,1,0,0,0,0},
//	{1,0,0,0,0,1,0,0,0,0}
//
//};
//int search_value(int array[])
//{
//
//	search_value();
//	return 0;
//}
//int main(void)
//{
//	
//	return 0;
//}
////struct _node
////{
////	int value;
////	struct _node * link;
////};
////typedef struct _node NODE;
////NODE *search_node(NODE *p, int key){
////	if(p == NULL )
////	{
////
////	}
////	if( p->value == key)
////	{
////		return p;
////	}
////	return search_node(p ->link, key);
////
////}
////int main(void)
////{
////	NODE a ={0};
////	NODE b ={0};
////	NODE c ={0};
////	NODE *rs;
////	a.value = 10;
////	b.value =20;
////	c.value =30;
////	a.link =&b;
////	b.link = &c;
////	c.link = NULL;
////	rs = search_node(&a,20);
////	printf("%d \n", rs->value);
////
////
////	//{
////	//	NODE *temp;
////	//	temp = &a;
////	//	while(temp)
////	//	{
////	//		if(temp->value ==20)
////	//		{
////
////	//		}
////	//		temp = temp ->link;
////	//	}
////	//}
////
////	return 0;
////}
/*
	Definition of Pointer 
	Variables is Memory
		Variable's Name and Address
	Pointer is Address
		Pointer Variable assign Address
*/
#include <stdio.h>

typedef	signed int	DataType;
typedef DataType	*PDataType;
int main( void ){
	DataType	var_name = 0;
	PDataType	pointer_name = NULL;	// NULL is (void*)(0)

	// about variables
	printf("%d	in var_name\n", var_name);
	printf("%d	is address of var_name\n", &var_name);
	printf("%d	<- what is this ? \n", *( &var_name ) );

	// about pointers
	printf("%d	in pointer_name\n", pointer_name);
	printf("%d	is address of pointer_name\n", &pointer_name);
	printf("%d	<- what is this ? \n", *( &pointer_name ) );
	printf("%d	<- why to be error ? \n", *(  pointer_name ) );



	return 0;
}

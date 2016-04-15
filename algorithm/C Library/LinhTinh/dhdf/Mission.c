#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _A{
	int a_seq;
	int field_2;
	int field_3;
};
struct _B{
	int b_seq;	//	primary key
	int a_seq;
	int field_3;
};
struct _C{
	int c_seq;
	int a_seq;
	int b_seq;
	int field_4;
};


int	join_table[];



// please see python
// OOP member and Struct member like DB table's fields
typedef	struct _person{
	int seq;
	char name[40];
}PERSON;

typedef struct _department{
	int code;
	char name[40];
	PERSON	members[20];
}DEPART;
typedef struct _info{
	int seq;
	char name[40];
}T;

T	Teams[10];
T	Members[20];

DEPART	Departs[10];

// Please Think Database structures

int main(void){
// T type have to merge process (relation)
	Teams[0].seq = 1;
	strcpy( Teams[0].name , "Mobile Dev");

	Teams[1].seq = 2;
	strcpy(Teams[1].name , "Web Dev");

	Members[0].seq = 1;
	strcpy(Members[0].name, "James Dean");

	// Depaty Type is one variable all data alread merge
	Departs[0].code = 1;
	strcpy(Departs[0].name, "Game Dev");
	Departs[0].members[0].seq = 10;
	strcpy(Departs[0].members[0].name, "James Down");

	return 0;
}
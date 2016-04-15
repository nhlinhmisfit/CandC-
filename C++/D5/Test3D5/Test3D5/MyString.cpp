#include <iostream>
using namespace std;
#include "MyString.h"

ostream & operator<<(ostream & o, const MyString & rsh)
{
	o<<rsh.GetData();
	return o;
}
istream & operator>>(istream & i,  MyString &rsh)
{
	char temp[1024];
	i.getline(temp, sizeof(temp));
	rsh = temp;
	return i;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define	RANDOM_MAX	100
#define	numsof(x)	(sizeof(x)/sizeof(*x))
#define	SWAP(a,b)	{ int t; t = (a); (a) =(b); (b)=t; }

#define	RandomArray(x)	{	\
	int i;					\
	for(i=0; i< numsof(x) ; ++i )	(x)[i] = rand()%(1+RANDOM_MAX);	\
}
#define	RandomString(x)	{	\
	int i;					\
	for(i=0; i< numsof(x) ; ++i )	(x)[i] = rand()%60+'A';	\
}
#define	PrintArray(x)	{	\
	int i;					\
	for(i=0; i< numsof(x) ; ++i )	printf("%d ", (x)[i]); printf("\n");	\
}
#define	PrintStep(a,z,s,p)	{\
	int k;\
	for(k=0; k<z; k++){\
		if( k==(s) || k==(p) )	printf("[%2d] ", a[k]);\
		else				printf(" %2d  ", a[k]);\
	}\
	printf("\n");\
}
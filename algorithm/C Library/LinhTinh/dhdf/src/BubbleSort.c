#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DnA.h"


int BubbleSort(int base[], int sz ){
	int i,j;
	int temp;
	for(i=0;i<sz;++i){
		for(j=sz-1;j>0;--j){
			if(base[j] < base[j-1] ){
				temp = base[j];
				base[j] = base[j-1];
				base[j-1] = temp;
			}
		}
	}
	return 0;
}
int main2(void){
	int aScores[20]={0};
	int els = numsof(aScores);
	int i;
	srand((unsigned int)time(NULL));

	RandomArray(aScores);
	PrintArray(aScores);
	BubbleSort(aScores, els);
	PrintArray(aScores);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DnA.h"

int SelectionSort(int base[], int sz ){
	int min;
	int i,j;
	int temp;
	for(i=0;i<sz;++i){
		min = i;
		for(j=min+1;j<sz;++j){
			if(base[min] > base[j] ){
				min = j;
			}
		}
		temp = base[i];
		base[i] = base[min];
		base[min] = temp;
	}
	return 0;
}
int main1(void){
	int aScores[20]={0};
	int els = numsof(aScores);

	srand((unsigned int)time(NULL));

	RandomArray(aScores);
	PrintArray(aScores);
	SelectionSort(aScores, els);
	PrintArray(aScores);

	return 0;
}
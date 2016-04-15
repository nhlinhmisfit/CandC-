#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DnA.h"

int ShakerSort(int base[], int sz ){
	int i, shift, left, right;
	int temp;

	left = 0;
	right = sz-1;	// 마지막 요소번호
	while( left<right ){
		for( i=left ;i < right ; ++i ){
			if( base[i] > base[i+1] ){
				temp = base[i];
				base[i] = base[i+1];
				base[i+1] = temp;
				shift = i;
			}
		}
		right = shift;
		for( i=right ;i > left ; --i ){
			if( base[i] < base[i-1] ){
				temp = base[i];
				base[i] = base[i-1];
				base[i-1] = temp;
				shift = i;
			}
		}
		left = shift;
	}
	return 0;
}
int main3(void){
	int aScores[20]={0};
	int els = numsof(aScores);
	int i;
	srand((unsigned int)time(NULL));

	RandomArray(aScores);
	PrintArray(aScores);
	ShakerSort(aScores, els);
	PrintArray(aScores);

	return 0;
}
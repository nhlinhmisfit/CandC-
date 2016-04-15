#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DnA.h"

int InsertionSort_Seo(int base[], int sz ){
	int i,j;
	int temp;
	for(i=1;i<sz;++i){
		temp = base[i];
		j = i-1;
		while(j>=1 && temp < base[j] ){
			base[j+1] = base[j];
			--j;
		}
		base[j+1] = temp;
	}
	return 0;
}
int InsertionSort(int base[], int sz ){
	int i,j;
	int temp;
	int loops = 0;
	for(i=1;i<sz;++i){
		temp = base[i];
		for(j = i-1; j>=0 && temp < base[j] ; --j ){
			base[j+1] = base[j];	// 요소를 하나씩 오른쪽으로(+1) 이동
			++loops;
		}
		base[j+1] = temp;
	}
	return loops;
}
int main4(void){
	int aScores[20]={0};
	int els = numsof(aScores);
	int i;
	srand((unsigned int)time(NULL));

	RandomArray(aScores);
	PrintArray(aScores);
	InsertionSort(aScores, els);
	PrintArray(aScores);

	return 0;
}

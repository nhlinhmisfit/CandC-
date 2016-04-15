#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DnA.h"


int main(void){
	int aScores[20]={0};
	int els = numsof(aScores);
	int i;
	srand((unsigned int)time(NULL));

	RandomArray(aScores);
	PrintArray(aScores);

	MergeSort(aScores, 0, els-1);
	
	PrintArray(aScores);

	return 0;
}

#include "SRC\DnA.h"

int	SelectionSort(int [], int );
int	BubbleSort(int [], int );
int InsertionSort(int [], int );
int ShellSort(int [], int );
int MergeSort(int [], int , int );
int QuickSort(int [], int, int);
int main(void){
	int aScores[10]={0};
	int els = numsof(aScores);

	srand((unsigned int)time(NULL));

	RandomArray(aScores);
	printf("Selection Sort \n");	SelectionSort(aScores, els);
	getchar();
	RandomArray(aScores);
	printf("Bubble Sort \n");		BubbleSort(aScores, els);
	getchar();
	RandomArray(aScores);
	printf("Insertion Sort \n");	InsertionSort(aScores, els);
	getchar();
	RandomArray(aScores);
	printf("Shell Sort \n");		ShellSort(aScores, els);
	getchar();
	RandomArray(aScores);
	printf("Merge Sort \n");		MergeSort(aScores, 0,els-1);
	getchar();
	RandomArray(aScores);
	printf("Quick Sort \n");		QuickSort(aScores, 0,els-1);
	getchar();

	return 0;
}
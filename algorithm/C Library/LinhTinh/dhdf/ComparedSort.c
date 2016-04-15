#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define ARYSIZE 2000
#define ROW 5
#define COL 10
#define SWAP1 19
#define	SWAP2 20
#define NUMTOPRINT 50
#define S "Shell Sort"
#define H "Heap Sort"
#define Q "Quick Sort"

void printSortLine (char *str);
void createAry (int *ary);
void printAry (int *ary, int size);
void shellSort (int list [], int last, int *compare, int *moves);
void printCmpAndMov (int compare, int moves, char *str);
void swap (int *ary);
void heapSort (int list[], int last, int *compare, int *move);
void quickSort (int sortData [], int left, int right, int *compare, int *move);

int main (void)
{
	int ary[ARYSIZE], heapAry [ARYSIZE], quickAry [ARYSIZE];
	int	compare = 0, moves = 0;

	createAry (ary);
	memcpy (heapAry, ary, ARYSIZE * sizeof (int));
	memcpy (quickAry, ary, ARYSIZE * sizeof (int));

	printf("Array size:\t%d\n\n", ARYSIZE);

	printSortLine (S);
	compare = moves = 0;
	shellSort (ary, ARYSIZE, &compare, &moves);
	printAry (ary, ARYSIZE);
	printCmpAndMov (compare, moves, "Random list Shell Sort:");
	swap (ary);
	compare = moves = 0;
	shellSort (ary, ARYSIZE, &compare, &moves);
	printCmpAndMov (compare, moves, "Nearly ordered list Shell Sort:");
/*
	printSortLine (H);
	compare = moves = 0;
	heapSort (heapAry, ARYSIZE - 1, &compare, &moves);
	printAry (heapAry, ARYSIZE);
	printCmpAndMov (compare, moves, "Random list Heap Sort:");
	swap (heapAry);
	compare = moves = 0;
	heapSort (heapAry, ARYSIZE - 1, &compare, &moves);
	printCmpAndMov (compare, moves, "Nearly ordered list Heap Sort:");
*/
	printSortLine (Q);
	compare = moves = 0;
	quickSort (quickAry, 0, ARYSIZE - 1, &compare, &moves);
	printAry (quickAry, ARYSIZE);
	printCmpAndMov (compare, moves, "Random list Quick Sort:");
	swap (quickAry);
	compare = moves = 0;
	quickSort (quickAry, 0, ARYSIZE - 1, &compare, &moves);
	printCmpAndMov (compare, moves, "Nearly ordered list Quick Sort:");
	exit(1);
	return 0;
}

void printSortLine (char *str)
{
	printf("\nPerforming %s....\n\n", str);
	return;
}

void createAry (int *ary)
{
	int i;

	for (i = 0; i < ARYSIZE; i++)
	{
		ary[i] = rand () % 1001;
	}
	return;
}

void printAry (int *ary, int size)
{
	int i, j;

	if (size <= NUMTOPRINT)
	{
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				printf("%4d   ", ary[(i * COL) + j]);
			}
			printf("\n");
		}
	}
	printf("\n");
	return;
}

void printCmpAndMov (int compare, int moves, char *str)
{
	printf("%-25s\t|compares = %6d  |  moves = %6d|\n", str, compare, moves);
	return;
}

void swap (int *ary)
{
	int temp;

	temp = ary[SWAP1];
	ary [SWAP1] = ary [SWAP2];
	ary [SWAP2] = temp;
	return;
}

void shellSort (int list [], int last, int *compare, int *moves)
{
	int hold, incre, curr, walker;

	incre = last / 2;
	while (incre != 0)
	{
		for (curr = incre; curr <= last; curr++)
		{
			hold = list [curr];
			*moves += 1;
			walker = curr - incre;
			while (((*compare)++,walker >= 0 && hold < list [walker]))
			{
				list [walker + incre] = list [walker];
				*moves += 1;

				walker = (walker - incre);
			}

			list [walker + incre] = hold;
			*moves += 1;
		}
		incre /= 2;
	}
	return;
}


void heapSort (int list[], int last, int *compare, int *move)
{
	void reheapUp (int heap[], int newElem, int *compare, int *move);
	void reheapDown (int heap[], int current, int last, int *compare, int *move);

	int sorted, holdData, walker;

	for (walker = 1; walker <= last; walker++)
	{
		reheapUp (list, walker, compare, move);
	}

	sorted = last;
	while (sorted > 0)
	{
		holdData = list [0];
		list [0] = list [sorted];
		list [sorted] = holdData;
		*move += 3;
		sorted--;
		reheapDown (list, 0, sorted, compare, move);
	}
	return;
}

void reheapUp (int *heap, int newNode, int *compare, int *move)
{
	int parent, hold;

	if (newNode)
	{
		parent = (newNode - 1)/2;
		if ( *compare += 1, heap [newNode] > heap [parent])
		{
			hold = heap[parent];
			heap[parent] = heap[newNode];
			heap[newNode] = hold;
			*move += 3;
			reheapUp (heap, parent, compare, move);
		}
	}
	return;
}

void reheapDown (int *heap, int root, int last, int *compare, int *move)
{
	int hold, leftKey, rightKey, largeChildKey, largeChildIndex;

	if ((root * 2 + 1) <= last)
	{
		leftKey = heap [root * 2 + 1];
		*move += 1;

		if ((root * 2 + 2) <= last)
		{
			rightKey = heap [root * 2 + 2];
			*move += 1;
		}
		else
		{
			rightKey = -1;
		}

		if (leftKey > rightKey)
		{
			largeChildKey = leftKey;
			largeChildIndex = root * 2 + 1;
		}
		else
		{
			largeChildKey = rightKey;
			largeChildIndex = root * 2 + 2;
		}

		if (*compare += 1, heap[root] < heap [largeChildIndex])
		{
			hold = heap [root];
			heap [root] = heap [largeChildIndex];
			heap [largeChildIndex] = hold;
			*move += 3;
			reheapDown (heap, largeChildIndex, last, compare, move);
		}
	}
	return;
}

void quickSort (int sortData [], int left, int right, int *compare, int *move)
{
#define MIN_SIZE 16

	void quickInsertion (int sortData[], int first, int last, int *compare, int *move);
	void medianLeft (int sortData[], int left, int right, int *compare, int *move);

	int sortLeft;
	int sortRight;
	int pivot;
	int hold;

	if ( (right - left) > MIN_SIZE)
	{
		medianLeft (sortData, left, right, compare, move);
		pivot = sortData [left];
		*move += 1;
		sortLeft = left + 1;
		sortRight = right;

		while (sortLeft <= sortRight)
		{
			while (*compare += 1, sortData [sortLeft] < pivot)
				sortLeft = sortLeft + 1;

			while (*compare += 1, sortData[sortRight] >= pivot)
				sortRight = sortRight - 1;

			if (sortLeft <= sortRight)
			{
				hold = sortData [sortLeft];
				sortData [sortLeft] = sortData [sortRight];
				sortData [sortRight] = hold;
				*move += 3;
				sortLeft = sortLeft + 1;
				sortRight = sortRight - 1;
			}
		}

		sortData [left] = sortData [sortLeft - 1];

		sortData [sortLeft - 1] = pivot;

		*move += 2;

		if (left < sortRight)
			quickSort (sortData, left, sortRight - 1, compare, move);
		if (sortLeft < right)
			quickSort (sortData, sortLeft, right, compare, move);
	}
	else
		quickInsertion (sortData, left, right, compare, move);
	return;
}

void quickInsertion (int sortData[], int first, int last, int *compare, int *move)
{
	int current;
	int hold;
	int walker;

	for (current = first + 1; current <= last; current++)
	{
		hold = sortData [current];
		*move += 1;
		walker = current - 1;
		while (*compare += 1, walker >= first && hold < sortData [walker])
		{
			sortData [walker + 1] = sortData [walker];
			*move += 1;
			walker = walker - 1;
		}
		sortData[walker + 1] = hold;
		*move += 1;
	}
	return;
}

void medianLeft (int sortData[], int left, int right, int *compare, int *move)
{
	int mid;
	int hold;

	mid = (left + right) / 2;

	if (*compare += 1, sortData [left] > sortData [mid])
	{
		hold = sortData [left];
		sortData [left] = sortData [mid];
		sortData [mid] = hold;  
		*move += 3;
	}
	if (*compare += 1, sortData [left] > sortData [right])
	{
		hold = sortData [left];
		sortData [left] = sortData [right];
		sortData [right] = hold;
		*move += 3;
	}
	if (*compare += 1, sortData [mid] > sortData [right])
	{
		hold = sortData [mid];
		sortData [mid] = sortData [right];
		sortData [right] = hold;
		*move += 3;
	}

	hold = sortData [left];
	sortData [left] = sortData [mid];
	sortData [mid] = hold;
	*move += 3;

	return;
}
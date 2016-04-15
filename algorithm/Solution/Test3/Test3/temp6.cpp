#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	typedef struct _student{
		int seq;
		char name[80];
		int score;
		char grade;//A B C D F
}BAN;
int print(BAN datas[],int size){// count of BANs
	int i;
	for(i=0;i<size;++i) {
		printf("Seq : %d - Name :%s \n", 
			(datas[i]).seq, (datas+i)->name );
		printf(" Score : %d, Grade : %c \n", 
			datas[i].score, datas[i].grade);
	}
	printf("\n");
	return 0;
}
int IntervalSort(BAN ar[], int size, int start, int interval);
int ShellSort(BAN base[], int size);
int compare_integer(void *a, void *b){
	int ca = *(int*)a;
	int cb = *(int*)b;
	return ( ca > cb );
}
int compare_string(void *a, void *b){
	int result = 0;
	const char *ca = (const char *)a;
	const char *cb = (const char *)b;
	if( strcmp(ca,cb) > 0 ){ result = 1; }
	return result;
}
int main( void ){
	int datas[20]={ 1,12,3,4,15,6,7,18,9,10,
		11,2,13,14,5,16,17,8,19,20};
	// srand((unsigned int)time(NULL)); set_random( datas, 20 );
	print(datas,20);
	ShellSort(datas,20);
	print(datas,20);
	return 0;
}
// shell sort funtion
// to explain algorithm with english
int IntervalSort(BAN a[], int start, int sz, int interval){
	int i;
	int p;
	BAN temp;
	int count = 0;
	int seq;
	for(i=start+interval;i<sz;i+=interval){
		p = i;
		temp = a[i];
		seq = a[i].seq;
		if( seq ){
			while( p>0 && a[p-interval].seq > temp.seq) ){
				a[ p ] = a[p-interval];
				p-=interval;
				++count;
			}
			a[p] = temp;
		}
		if( name ){
			while( p>0 && a[p-interval].seq > temp.seq) ){
				a[ p ] = a[p-interval];
				p-=interval;
				++count;
			}
			a[p] = temp;
		}
	}
	return count;
}
int ShellSort(BAN base[], int size){
	int interval;
	int i;
	int count=0;
	interval = n;//20
	while (interval >= 1){
		interval = interval / 2;//10 5 2 1 0
		for (i = 0; i < interval; i = i + 1) {
			//insertion sort for segment array
			count += IntervalSort(base, i, n, interval);
			// print(base,n);
			// getchar();
		}
		printf("end interval[%d]---------------------\n",interval);
	}
	printf("total count of loop %d\n", count);
	return 0;
}
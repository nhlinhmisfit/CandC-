
#include "src\dna.h"
#include <windows.h>

int Map[20][20]={
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,
	1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,1,1,0,1,1,
	1,0,0,0,1,1,0,1,1,0,0,0,1,0,0,0,0,0,1,1,
	1,0,1,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,
	1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,
	1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,1,
	1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0,1,1,
	1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,1,0,1,1,
	1,0,1,0,1,1,1,0,1,0,1,0,1,1,0,1,1,0,1,1,
	1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,1,0,1,1,
	1,0,1,1,1,1,1,0,1,0,1,0,1,1,0,1,1,0,1,1,
	1,0,0,0,0,0,0,0,1,0,1,0,1,1,0,1,1,0,1,1,
	1,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0,1,1,
	1,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,1,
	1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};
int	er,ec;
int	route[400][2];
int	sp;
int	min_route[400][2];
int min=400, max=0;
int	max_route[400][2];

void gotoxy(int row, int col){
	COORD	pos;
	pos.X = col*3;
	pos.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int replay(int *pos, int n){
	int r, c;
	char nstr[8]={0};
	itoa(n,nstr,10);
	r = pos[0];
	c = pos[1];
	gotoxy(r,c);
	printf("%s",nstr);
	return 0;
}
int	display(void){
	int i,j;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
//			printf("%s ", (Map[i][j]==1)?"бс":(Map[i][j]==2)?"б┘":"  ");
			printf("%s_", (Map[i][j]==1)?"бс":"  ");
		}
		printf("\n");
	}
	return 0;
}
int explorer(int row, int col){
	static	int success;
	static	int	stack;
	Map[row][col]=2;
	system("cls");
	stack++;
	printf("[%d]explorer(%d, %d)\n", stack, row,col );
	display();
	Sleep(50);	//	_getch();
	if( row==er && col==ec ){
	printf("[%d]explorer	Success Escape\n", stack );
		success = 1;
	}
	if( Map[row][col+1] == 0 )	explorer(row, col+1);
	if( Map[row+1][col] == 0 )	explorer(row+1, col);
	if( Map[row][col-1] == 0 )	explorer(row, col-1);
	if( Map[row-1][col] == 0 )	explorer(row-1, col);

	printf("[%d]explorer(%d, %d) return \n", stack, row,col );
	_getch();
	stack--;
	Map[row][col] = 0;
	return success;
}

int tracker(int row, int col);

int main(void){
	int	sr = 1;
	int sc = 0;
	int i;
	er = 18;
	ec = 19;
//	explorer(sr,sc);
	tracker(sr,sc);
	system("cls");
	display();
	for(i=0;i<min;i++){
		replay(min_route[i],i);
		Sleep(100);
	}
	gotoxy(20,0);
	printf("Min path : %d \n", min );
	_getch();
	system("cls");
	display();
	for(i=0;i<max;i++){
		replay(max_route[i],i);
		Sleep(100);
	}
	gotoxy(20,0);
	printf("Max path : %d \n", max );
	return 0;
}
int tracker(int row, int col){
	static	int success;
	int i;

	Map[row][col]=2;
	route[sp][0] = row;
	route[sp][1] = col;
	sp++;
	if( row==er && col==ec ){
		if( sp < min ){
			min = sp;
			memcpy(min_route, route, sizeof(route));
		}
		if( sp > max ){
			max = sp;
			memcpy(max_route, route, sizeof(route));
		}
		success = 1;
	}
	if( Map[row][col+1] == 0 )	tracker(row, col+1);
	if( Map[row+1][col] == 0 )	tracker(row+1, col);
	if( Map[row][col-1] == 0 )	tracker(row, col-1);
	if( Map[row-1][col] == 0 )	tracker(row-1, col);
	sp--;
	Map[row][col] = 0;
	return success;
}
int tracker_original(int row, int col){
	static	int success;
	int i;

	Map[row][col]=2;
	route[sp][0] = row;
	route[sp][1] = col;
	sp++;
	if( row==er && col==ec ){	
		system("cls");
		display();
		for(i=0;i<sp;i++){
			replay(route[i],i);
			Sleep(100);
		}
		success = 1;
	}
	if( Map[row][col+1] == 0 )	tracker(row, col+1);
	if( Map[row+1][col] == 0 )	tracker(row+1, col);
	if( Map[row][col-1] == 0 )	tracker(row, col-1);
	if( Map[row-1][col] == 0 )	tracker(row-1, col);
	sp--;
	Map[row][col] = 0;
	//if( !success && Map[row][col+1] == 0 )	tracker(row, col+1);
	//if( !success && Map[row+1][col] == 0 )	tracker(row+1, col);
	//if( !success && Map[row][col-1] == 0 )	tracker(row, col-1);
	//if( !success && Map[row-1][col] == 0 )	tracker(row-1, col);
	return success;
}
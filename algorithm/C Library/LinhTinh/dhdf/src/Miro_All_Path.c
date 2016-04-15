
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int gotoxy(int x, int y){
	COORD	pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	return 0;
}

#define	FAIL	0
#define	DONE	1

#define	ROW	15
#define	COL	15

#define	IN_ROW	1
#define	IN_COL	0
#define	OUT_ROW	(ROW-2)
#define	OUT_COL	(COL-1)

int szMaze[ROW][COL] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,0,1,1,1,0,1,1,0,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,
	1,0,1,1,1,1,0,1,1,0,0,0,1,0,1,
	1,0,0,0,0,1,0,0,0,1,0,1,1,0,1,
	1,1,1,1,0,1,0,1,1,1,0,1,0,0,1,
	1,0,0,0,0,1,0,1,0,0,0,1,1,0,1,
	1,0,1,1,0,1,0,1,1,1,0,1,0,0,1,
	1,0,1,0,0,1,0,0,0,0,0,1,0,1,1,
	1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,
	1,0,0,0,1,0,0,0,1,1,0,1,0,1,1,
	1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};
int	szPath[ROW*COL][3];
int sp;
int success=FAIL;

int	tracker(int , int);

int display(void){
	int i,j,k;

	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			k = szMaze[i][j];
			printf("%s", (k==1)?"¢Æ" : "  " );
		}
		printf("\n");
	}
	return 0;
}

int replay(void){
	int i,j,k;
	int row, col;
	int _sp = -1;
	static int path;

	system("cls");
	printf("Path[ %d ] - (Row,Col)\n", path++);
	display();
	while(_sp<sp-1){
		_sp++;
		row = szPath[_sp][0];
		col = szPath[_sp][1];
		gotoxy(col*2,row+1);
		printf("£À");
//		Sleep(100);
	}
	gotoxy(0,ROW+1);
	system("pause");
	return 0;
}
int miro_main(void){

	printf("¹Ì·Î °æ·Î Å½»ö\n");
	if( tracker(IN_ROW, IN_COL) == FAIL ){
		printf("Å½»ö ½ÇÆÐ\n");
	}else{
		printf("\n");
	}
	return 0;
}

int printPath(void){
	int i;
	static int path = 1;
	
	printf("Path[ %d ] - (Row,Col)\n", path++);
	for(i=0;i<sp;i++){
		printf("(%2d,%2d)	", szPath[i][0], szPath[i][1]);
	}
	printf("\n");

	return 0;
}
int tracker(int row, int col){
	int	i;

	szMaze[row][col] = 2;
	szPath[sp][0] = row;	szPath[sp][1] = col;	sp++;
	if( row==OUT_ROW	&& col==OUT_COL ){
		replay();
		success = DONE;
	}
	if(szMaze[row][col+1] == 0 )	tracker(row, col+1);
	if(szMaze[row+1][col] == 0 )	tracker(row+1, col);
	if(szMaze[row][col-1] == 0 )	tracker(row, col-1);
	if(szMaze[row-1][col] == 0 )	tracker(row-1, col);
	
	sp--;
	szMaze[row][col] = 0;
	return success;
}
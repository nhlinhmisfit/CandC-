#include <stdio.h>
#include "string.h"
#include "windows.h"
#include "conio.h"
//int main(void)
//{
//	char  rquest_title[20][80] = {0};
//	int seq = 0;
//
//	do
//	{
//		//if(seq = 20) { break;}
//		printf ( "your request issue: ");
//		gets(rquest_title[seq++]);
//	}while(seq <20 && strlen(rquest_title[seq-1]));
//
//	do 
//	{
//		--seq;
//		printf("[%d] %s \n", seq, rquest_title[seq]);
//	} while (seq);
//	 printf("%d ", seq);
//	return 0;
//}
#define X_AXIS 0
#define Y_AXIS 1

int display(int x, int y)
{
	int row, col;
	system("cls");
	for(row = 0 ; row <20; ++row){
		for(col =0; col <30; ++col){
			printf("%s",(row ==y && col == x)? "(^=^)": " ");
		}
		printf("\n");
		}
	return 0;
}

int main(void)
{
	int sx,sy;

	int start_pos[100][2]= {0};
	int seq =0;


	sx =0;
	sy =0;

	while(!kbhit()){
		display(sx,sy);

		start_pos[seq][X_AXIS] = sx;
		start_pos[seq][Y_AXIS] = sy;
		++seq;
		if(seq ==100){break;}

		sx += rand()%3 -1;
		sy += rand()%3 -1;
		
		if(sx < 0) sx =0;
		if(sy >29) sy =29;
		if(sy < 0) sy =0;
		if(sx >19) sx =19;
		
	}
	while(seq)
	{
		sx = start_pos[seq][X_AXIS];
		sy =start_pos[seq][Y_AXIS];
		--seq;
		display(sx,sy);
		getch();
	}
//reverse process using stack
	return 0;
}
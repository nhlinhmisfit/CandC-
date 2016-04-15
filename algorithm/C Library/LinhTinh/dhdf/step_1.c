

#include <stdio.h>
#include <conio.h>	// for kbhit()
/* Message Queue on Operating System 
	Call Center : customer's request list is queue
*/
#define	X_AXIS	0
#define Y_AXIS	1

int display(int x, int y){
	int row, col;

	system("cls");//only use windows
	for(row=0;row<20;++row){
		for(col=0;col<30;++col){
			printf("%s", (row==y && col==x) ? "¡Ú" : "  ") ;
		}
		printf("\n");
	}

	return 0;
}
int main( void ){
	int	sx, sy;
	int	star_pos[100][2]={0};
	int seq = 0;

	sx = 0;	//is col
	sy = 0;	//is row
	while( !kbhit() ){
		display(sx,sy);
		star_pos[seq][X_AXIS] = sx;
		star_pos[seq][Y_AXIS] = sy;
		++seq;
		if( seq == 100 ){	break;	}
		sx += rand()%3-1;
		sy += rand()%3-1;

		if(sx < 0 )	sx = 0;
		if(sx > 29 )	sx = 29;
		if(sy < 0 )	sy = 0;
		if(sy > 19 )	sy = 19;

	}
	while( seq ){
		sx = star_pos[seq][X_AXIS];
		sy = star_pos[seq][Y_AXIS];
		--seq;
		display(sx,sy);
		getch();
	}
	// if you have reverse process, using stack
	return 0;
}

int main_2( void ){
	char	rquest_title[20][80]={0};	// sizeof(char) x 20 x 80
	int		seq = 0;

	do{
//		if( seq == 20 ){	break;	}
		printf("your request issue : ");
		gets( rquest_title[seq++] );
//		if( seq == 19 ){	break;	}
	}while( seq<20 && strlen( rquest_title[seq-1] )  );
	// stop when only press enter 0 is false

	do{
		--seq;
		printf("[%d] %s \n", seq, rquest_title[seq] );
	}while(seq);

	printf(" seq is %d \n", seq );



	return 0;
}

int main_1( void ){
	int	ar[ 20 ] = {0};
	int i;

	/*	Stack Structure using Array */
	for( i=0; i<20; ++i){
		ar[i] = i+1;
	}

	for( i=19; i>=0; --i){
		printf( " %d %d \n", i, ar[i]);
	}

	/*	Queue Structure using Array
	for( i=0; i<20; ++i){
		ar[i] = i+1;
	}

	for( i=0; i<20; ++i){
		printf( " %d %d \n", i, ar[i]);
	}
	*/

	return 0;
}
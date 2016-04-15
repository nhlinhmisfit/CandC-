#include	<stdio.h>
#include	"MapData.inc"

/*
	Recursive call 

	1.	looks like Loop
	2.	do not use when too many data
		have limit about 4000 times x int type
		Virtual Memory Menagement default size / 1 application
	3.	general use Sorting, Searching
		Tree, Graph
			if you cannot use recursive call then cannot use
	very important

	Basic Template
	recursive_call_func(){
		if( when stop (Loop) ){
			must have this line
		}
		pre_process
		recursive_call();
		post_process
	}
*/

/*	EscapeMaze	*/


#define	SIZE	20
#define	EXIT	3
#define	WALL	1
#define	ROAD	0

char	(*Maze)[20];
int	x,y;

typedef	enum	{false, true}	BOOL;
void	Go(void);
void	turnRight(void);
void	turnLeft(void);
BOOL	isWall(void);
BOOL	isEscaped(void);

int	main(void){

	Maze[SIZE-1][SIZE-1]=EXIT;
	
	do{
		if(isWall()){
			turnRight();
		}
		Go();
	}while( ! isEscaped() );

	return 0;
}

BOOL	isWall(void){

	if( Maze[y][x] == ROAD ){
		return 	false;
	}
	if( Maze[y][x] == WALL ){
		return	true;
	}

}
BOOL	isEscaped(void){

	if( Maze[y][x] == EXIT ){
		return 	true;
	}
	return	false;

}


char	MapData[16][16]={
1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,
0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	1,
1,	0,	1,	0,	0,	1,	1,	1,	1,	1,	0,	1,	0,	1,	1,	1,
1,	0,	0,	1,	0,	1,	0,	1,	0,	0,	0,	0,	0,	1,	0,	1,
1,	0,	1,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	1,	0,	1,
1,	0,	0,	1,	1,	0,	1,	0,	1,	0,	1,	0,	0,	1,	0,	1,
1,	1,	0,	0,	1,	0,	1,	0,	0,	0,	1,	0,	1,	1,	0,	1,
1,	0,	1,	0,	1,	0,	1,	0,	1,	1,	1,	0,	0,	0,	0,	1,
1,	0,	0,	0,	1,	0,	0,	0,	1,	0,	1,	1,	1,	0,	1,	1,
1,	0,	1,	1,	1,	1,	0,	1,	1,	0,	1,	0,	1,	0,	1,	1,
1,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,
1,	0,	1,	0,	1,	0,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,
1,	0,	1,	0,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,
1,	0,	1,	0,	0,	0,	1,	0,	1,	1,	1,	1,	0,	1,	0,	1,
1,	0,	1,	0,	1,	0,	1,	0,	1,	0,	0,	1,	0,	1,	0,	0,
1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1
};

/*
	Trainning forr Stack , Tree, LinkedList
	by Jang
*/
#include "src/dna.h"


int dir_main( void ){
	char	cmd[128];
	char	*path[512]={"C:\\"};
	while(1){
		printf("%s>", path);
		memset(cmd,0,sizeof(cmd));
		gets(cmd);
		if(!strcmp(cmd,"exit")){
			break;
		}
	}
	return 0;
}
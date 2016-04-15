#include <stdio.h>
#include <string.h>
char	tagNames[512][64];
int		row, col;
int		isPaired;// 0


int	SaveTagName(FILE *fp){
	int	ch;
	ch = fgetc(fp);
	if( ch == '>' )
	{
		return 0;
	}

	tagNames[row][col] = ch;
	++col;
	SaveTagName(fp);
	return 0;
}

int PrintValues(FILE *fp)
{
	int ch;
	if(feof(fp))	return EOF;

	ch = fgetc(fp);
	if( ch == '<' ){
		return 1;
	}
	if(!(ch==' '||ch=='\t'||ch=='\r'||ch=='\n') ){
		putc(ch, stdout);
	}
	PrintValues(fp);
	return 0;
}

int ReadTag(FILE *fp)
{
	int	ch;
	if(feof(fp)){
		return EOF;	// End Of File
	}
	ch = fgetc(fp);
	if( ch == '<'){
		//SaveTagName(fp);
		printf("\n");
		if(tagNames[row][1]!='/'){	// this tag name is start tag		
			PrintValues(fp);
			fseek(fp,-1,SEEK_CUR);
		}
		++row;
		col = 0;		
	}
	ReadTag(fp);	
	return 0;
}

int	printTagNames(void){
	int count_rows;
	int i;
	for(i=0;i<512;++i)
	{
		if( 0==strlen(tagNames[i]) )	break;
		printf("[%2d]	%s\n", i, tagNames[i]);		
	}
	
	count_rows = i;
	return count_rows;
}
int main(void)
{
	const char *fName= "DataFile.txt";
	FILE *fp;
	char readBuffer[512] = {0};

	int fsize; 
	char Line[100][512] = {0};

	fp = fopen(fName,"r");
	if(fp ==NULL)
	{
		printf("Not found %s \n", fName);
		return EOF;  //-1
	}

//	ReadTag(fp);
	printf("\n");
	fclose(fp);
	printTagNames();
	/*for(int i =0 ; i<100 ; i++)
	{
	if(fgets(readBuffer, 512, fp))
	{
	strcpy(Line[i], readBuffer);
	}
	else {break;}
	memset(readBuffer,0, 512);
	}
	for(int i = 0 ; i<100; i++)
	{
	if(Line[1][0])
	printf("%s", Line[i]);
	}*/
	
	//fseek(fp,0,SEEK_END); //2 move to file end
	//fsize = ftell(fp); //file size
	//fseek(fp,0, SEEK_SET);// to start
	//fread(readBuffer,sizeof(char),fsize,fp);
	//printf("%s", readBuffer);

	//printf("%d Bytes", fsize);

	//while( fgets(readBuffer, sizeof(readBuffer),fp))
	//{
	//	printf("%s", readBuffer);
	//	memset(readBuffer,0, 512); //strlen(readBuffer) -- clean readBuffer
	//}
	return 0;
}
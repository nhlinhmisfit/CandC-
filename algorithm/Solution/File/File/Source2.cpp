//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//
//int main(){
//	
//	int i = 0;
//	int Linsize = 1024;
//	char *words[100];
//	FILE *fp = fopen("DataFile.txt", "r");
//	if (fp == 0){
//		fprintf(stderr, "Error while opening");
//		exit(1);
//	}
//
//	words[i] =(char *) malloc(Linsize);
//
//	while (fgets(words[i],Linsize, fp)) 
//	{
//		i++;
//		words[i] =(char *) malloc(Linsize);
//		
//	} 
//	int i1 =i;
//	for(int i =0; i<i1;i++)
//	{
//		printf("%s", words[i]);
//	}
//	return 0;
//}
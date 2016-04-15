#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char command[80] =  {0};
	char arg[80] = {0};
	char path[512] = {"C:\\"};
	while(1)
	{
		printf("%s>", path);
		gets(command);
		scanf(buffer, "%s , %s", command, arg);
		if(strcmp(command, "cd")==0)
		{
			strcat(path, arg);
			strcat(path, "\\");
		}
	}
	return 0;
}
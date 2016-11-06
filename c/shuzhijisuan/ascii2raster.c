#include<stdio.h>
#include<stdlib.h>
#include"./raster.h"

int getWord(char *word, FILE *fp);

int main(void)
{
	char path[] = "./dem2.txt";
	ascii2raster(path);
	return 0;
}

int ascii2raster(char *asciiPath)
{
	pRaster praster;

	FILE *fp;
	char *fc;
	char *word = (char*)malloc(sizeof(char)*50);
	char *w;
	int state;
	
	if((fp=fopen(asciiPath,"r")) == NULL)
	{
		printf("fail to open file");
		getchar();
		exit(1);
	}

	while((state=getWord(word,fp)) == 0)
	{
		printf("%s|\n",word);
	}
	if(state==1) printf("%s|\n",word);

	fclose(fp);
	return 0;
}

int getWord(char *word, FILE *fp)
{
	char *w = word;
	char c;
	while(1)
	{
		c=fgetc(fp);
		if(c==EOF) return -1;
		if(c!=' ' || c!='\n') break;
	}

	while(c!=' ' || c!='\n' || c!=EOF)
	{
		*w++ = c;
		c=fgetc(fp);
	}

	*w = '\0';
	if(c==EOF) return 1;

	return 0;
}


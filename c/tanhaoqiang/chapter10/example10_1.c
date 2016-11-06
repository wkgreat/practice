#include<stdio.h>
#include<stdlib.h>

int mine(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	char filename[20];
	char filename2[20];
	char ch;
	FILE *fp;
	FILE *fp2;
	printf("Please enter filename: ");
	scanf("%s", filename); getchar();
	printf("Please enter filename2: ");
	scanf("%s", filename2); getchar();
	printf("filename: %s\n", filename);
	if(!(fp=fopen(filename,"r")))
	{
		printf("Open file error!");
		exit(0);
	}
	if(!(fp2=fopen(filename2,"w")))
	{
		printf("open file error!");
		exit(0);
	}
	while((ch=getc(fp))!=-1)
	{
		fputc(ch,fp2);
	}
	putchar(10);
	close(fp);
	close(fp2);
	return 0;
}

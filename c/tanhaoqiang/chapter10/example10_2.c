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
	char temp[100];
	FILE *fp;
	FILE *fp2;
	char ch;
	printf("Please enter a filename: ");
	scanf("%s", filename); getchar();
	printf("Please enter a filename: ");
	scanf("%s", filename2); getchar();
	if(!(fp=fopen(filename,"r")))
	{
		printf("Opne file error!");
		exit(0);
	}
	if(!(fp2=fopen(filename2,"w")))
	{
		printf("Open file error!");
		exit(0);
	}

	while(fgets(temp,100,fp))
	{
		fputs(temp,fp2);
		puts(temp);
	}

	putchar(10);
	fclose(fp);
	fclose(fp2);

	return 0;
}

#include<stdio.h>
#define MAXLINE 1000

int mygetline( char a[], int max);

main()
{
	char line[MAXLINE];
	int len;
	
	printf("Please enter some text:\n");

	while((len = mygetline(line, MAXLINE)) > 1)
	{
		printf("last line:  %s", line);
		printf(">>>");
	}

	return 0;
}

/* 自编getline函数，从命令行读取文本行,并返回行的长度*/
int mygetline(char line[], int max)
{
	int c, i;

	for(i = 0; i < max-1 && (c=getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;
	}
	if (c == '\n')
	  line[i++] = '\n';
	line[i] = '\0';

	return i;

}

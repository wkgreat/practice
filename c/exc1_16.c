#include<stdio.h>
#define MAXLINE 10000

/*  excercise 1_16 page 30*/

int mygetline(char line[], int maxline );

main()
{
	char line[MAXLINE];
	while(mygetline(line, MAXLINE))
	{
		printf("%s", line);
	}

	printf("end!!!");

	return 0;
}

int mygetline(char line[], int maxline)
{
	char *pline = line;
	int length = 0;
	char c;

	for(length = 0 ;((c=getchar()) != EOF) && maxline > 1; maxline--, length++)
	{
		if( c == '\n')
		{
			*pline++ = '\n';
			*pline++ = '\0';
			return ++length;
		}
		else
		{
			*pline++ = c;
			++length;
		}
	}
	return 0;
}

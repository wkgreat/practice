#include<stdio.h>
#define MAXLINE 10000

/* excercise 1_18  */
/* not successful */

int mygetline(char line[], int maxline);
int trim(char line[], int length);

main()
{
	char line[MAXLINE];
	int length;
	printf("not successful\n");

	while(length = mygetline(line, MAXLINE))
		if(length > 0)
		  printf("%s%c%d\n", line,'|',length);

	return 0;
}

int mygetline(char line[], int maxline)
{
	char *pline = line;
	int i;
	int length;
	char c;

	for(length = 0; (c=getchar()) != EOF && maxline > 1; maxline--)
	{
		if( c == '\n' )
		{
			if(length == 0)
			  return 0;
			else
			{
				*pline++ = '\0';
				length = trim(line, length);
				return length;
			}
		}
		else
		{
			*pline++ = c;
			++length;
		}

	}
}

int trim(char line[], int length)
{
	char *pline = line;
	char *pline_start = line;
	int pline_move = 1;
	char *pline2 = line + length - 1;
	//printf("@@@ %c @@@", *pline2);
	int pline2_move = 1;
	for(;(pline2 - pline > 0) && ( pline_move || pline2_move);)
	{
		//printf("^^^%c\n", *pline);
		if( pline_move && (*pline == ' ' ||  *pline == '\t') )
		  pline++;
		else
		  pline_move = 0;
		if( pline2_move && (*pline2 == ' ' || *pline2 == '\t'))
		  pline2--;
		else
		  pline2_move = 0;
	}
	if(pline == pline2)
	{
		if(*pline == ' ' || *pline == '\t')
		{
			return 0;
		}
		else
		{
			*(pline+1) = '\0';
			return 1;
		}
	}
	else if(pline > pline2)
	  return 0;
	else 
	{
		//printf(" ### %c ###",  *(pline2));
		*(pline2+1) = '\0';
		return pline2-line+1;
	}
}

#include<stdio.h>

int mine(void);
int book(void);
int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	char a[81];
	printf("Please enter a string>>>\n");
	gets(a);
	int in=0, i=-1, n=0;
	while(a[++i])
	{
		if(a[i]>='a' && a[i]<='z' || a[i]>='A' && a[i]<='Z')
		{
			if(!in)
			{
				n++;
				in=1;
			}
		}else in=0;
	}
	printf("The result is: %d\n", n);
	return 0;
}

int book(void)
{
	char string[81];
	int i, num=0, word=0;
	char c;
	grts(string);
	for(i=0;(c=string[i])!='\0';i++)
	if(c==' ') word=0;
	else if(word==0)
	{
		word=1;
		num++;
	}
	printf("There are %d words in this line. \n", num);
	return 0;
}

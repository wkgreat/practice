#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int mine(void);
int sort(char *[], int n);

int book(void);

int main(void)
{
	printf("not success!");
	mine();
	return 0;
}

int mine(void)
{
	char a[50];
	char *p[5];
	int i;
	for(i=0;i<5;i++)
	{
		printf("pelase enter the %dth string>>>", i);
		gets(a);
		*(p+i) = (char *)malloc(50*sizeof(char));
		strcpy(*(p+i), a);
	}
	sort(p,5);
	for(i=0;i<5;i++)
	{
		puts(*(p+i));
	}
	puts("\n");
	return 0;
}

int sort(char *p[], int n)
{
	char *temp;
	int i, j;
	for(i=0;i<5;i++)
	  for(j=i+1;j<5;j++)
		if(strcmp(*(p+i),*(p+j))>0)
		{
			temp = *(p+i);
			*(p+i) = *(p+j);
			*(p+j) = temp;
		}
	return 0;
}

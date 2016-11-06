#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	char a[81], b[81], c[81];
	int w = 0;
	gets(a);
	gets(b);
	gets(c);
	int i=-1;
	char *p = a;
	while(a[++i] && b[i] && c[i])
	{
		if(p[i] < b[i])
		  p = b;
		if(p[i] < c[i])
		  p = c;
	}
	printf("The result is: >>>");
	puts(p);
	printf("\n");
}

#include<stdio.h>

int max(int,int);

int main(void)
{
	int a, b, c, d;
	int e;
	scanf("%d%d%d%d",&a, &b, &c, &d);
	e = max(max(max(a,b),c),d);
	printf("%d",e);
	printf("\n");return 0;
}

int max(int a, int b)
{
	return a>b?a:b;
}

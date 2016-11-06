#include<stdio.h>

int max(int ,int);

int main(void)
{
	int a, b;
	scanf("%d%d",&a,&b);
	int c = max(a, b);
	printf("%d",c);
	printf("\n"); return 0;
}

int max(int a, int b)
{
	if(a>b)
	  return a;
	else return b;
}

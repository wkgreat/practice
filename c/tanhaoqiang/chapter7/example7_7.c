#include<stdio.h>

int jiecheng(int n);

int main(void)
{
	int a;
	scanf("%d", &a);
	printf("%d", jiecheng(a));
	printf("\n"); return 0;
}

int jiecheng(int n)
{
	if(n==0 || n==1)
	  return 1;
	else
	  return jiecheng(n-1)*n;
}

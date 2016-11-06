#include<stdio.h>

int func(int n);

int main(void)
{
	int a;
	scanf("%d", &a);
	printf("%d",func(a));
	printf("\n"); return 0;
}

int func(int n)
{
	if(n==1)
	  return 10;
	else 
	  return func(n-1)+2;
}

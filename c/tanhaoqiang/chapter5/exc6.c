#include<stdio.h>

int mine(void);
int jiecheng(int);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	int n, result;
	printf("Please enter a integer>>>");
	scanf("%d", &n);
	printf("The result is: %d\n", jiecheng(n));
	return 0;
}

int jiecheng(int n)
{
	if(n==0 || n==1)
	  return 1;
	else
	  return n*jiecheng(n-1);
}

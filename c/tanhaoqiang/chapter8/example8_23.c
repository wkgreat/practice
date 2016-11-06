#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	printf("\n");return 0;
}

int mine(void)
{
	int max(int, int);
	int min(int ,int);
	int compare(int, int, int(*)(int, int));
	int (*c)(int, int);
	printf("1:max 2:min>>>");
	unsigned short int a;
	scanf("%hu", &a);
	int b;
	b = a==1?(compare(1,100,max)):(compare(1,100,min));
	printf("%d",b);
	return 0;
}

int max(int a, int b)
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a>b?b:a;
}
int compare(int a, int b, int (*c)(int, int))
{
	return (*c)(a,b);
}

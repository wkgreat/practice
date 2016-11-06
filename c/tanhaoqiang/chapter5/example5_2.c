#include<stdio.h>

int mine(void);
int book(void);

int main(void)
{
	mine();
	book();
	return 0;
}

int mine(void)
{
	int i=1, sum=0;
	do
	{
		sum+=i;
	}while(++i<=100);
	printf("The result is: %d\n", sum);
	return 0;
}

int book(void)
{
	int i=1, sum=0;
	do
	{
		sum=sum+i;
		i++;
	}while(i<=100);
	printf("sum=%d\n", sum);
	return 0;
	return 0;
}

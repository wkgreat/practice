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
	int i=0, sum=0;
	while(++i<=100)
	  sum+=i;
	printf("The result is: %d\n", sum);
	return 0;
}

int book(void)
{
	int i=1, sum=0;
	while(i<=100)
	{
		sum=sum+i;
		i++;
	}
	printf("sum=%d\n", sum);
	return 0;
	return 0;
}

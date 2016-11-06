#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	int i;
	int a[20]={1,1};
	for(i=2;i<20;++i)
	{
		a[i] = a[i-1]+a[i-2];
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

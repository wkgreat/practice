#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	int a[10], i;
	for(i=0;i<10;++i)
	{
		a[i] = i;
		printf("%d ", a[i]);
	}
	printf("\n");
	for(i=9;i>=0;--i)
	  printf("%d ", a[i]);
	printf("\n");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

int mine(void);
int pan(int *, int, int);

int main(void)
{
	mine();
	printf("\n");
	return 0;
}

int mine(void)
{
	int a[10];
	int *p1, *p2;
	p1 = a;
	int i;
	for(i=0;i<10;i++)
	{
		*(p1+i) = i;
		printf("%d ", i);
	}
	printf("\n");
	pan(a,10,3);
	for(i=0;i<10;i++)
	  printf("%d ", a[i]);
	return 0;
}

int pan(int *a, int length, int n)
{
	int b[n];
	int i,j;
	for(i=length-n,j=0;i<=length-1;i++,j++)
	{b[j] = a[i];}
	for(i=length;i>=n;i--)
	{
		a[i] = a[i-n];
	}
	for(i=0;i<n;i++)
	{
		a[i] = b[i];
	}
	return 0;
}
		

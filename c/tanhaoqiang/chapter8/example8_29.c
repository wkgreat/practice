#include<stdio.h>

int mine(void);

int main(void)
{
	book();
	printf("\n");return 0;
}

int mine(void)
{
	int* a[10];
	int b[10]={1,2,3,4,5,6,7,8,9,10};
	int **p=a;
	int i=0;
	while(i<10)
	{
		*p = b+i;
		i++;p++;
	}
	i=0;p=a;
	while(i<10)
	{
		printf("%d\n",**p++);
		i++;
	}
	return 0;
}

int book(void)
{
	int a[5] = {1,2,3,4,5};
	int *num[5] = {&a[0],&a[1],&a[2],&a[3],&a[4]};
	int **p,i;
	p=num;
	for(i=0;i<5;i++)
	{
		printf("%d",**p++);
	}
	printf("\n");
	return 0;
}

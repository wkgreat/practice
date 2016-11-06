#include<stdio.h>

int mine(void);
int book(void);

int main(void)
{
	book();
	return 0;
}

int mine(void)
{
	int f1=1, f2=1, f3=0;
	int i=0;
	while(++i<=5)
	{
		printf("%d\n", f1);
		f3 = f1+f2;
		f1 = f2;
		f2 = f3;
	}
	return 0;
}

int book(void)
{
	int f1=1, f2=1;
	int i;
	for(i=1;i<=20;i++)
	{
		printf("%12d %12d", f1, f2);
		if(i%2==0) printf("\n");
		f1 = f1+f2;
		f2 = f1+f2;
	}
	return 0;
}

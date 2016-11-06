#include<stdio.h>

int func(int, int n);

int main(void)
{
	int a;
	printf("Please enter a 4-digits number>>>");
	scanf("%d", &a);
	func(a, 4);
	printf("\n"); return 0;
}

int func(int a, int n)
{
	int b1, b2;
	while(a)
	{
		b1 = a%1000;
		b2 = (a-b1)/1000;
		printf("%d ", b2);
		a = b1*10;
	}
	return 0;
}

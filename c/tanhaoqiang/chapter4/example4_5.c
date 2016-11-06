#include<stdio.h>

int mine(void);
int book(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	double a;
	int b;
	printf("Please enter a number>>> ");
	scanf("%lf", &a);

	if(a < 0)
	  b = -1;
	else if(a == 0)
	  b = 0;
	else 
	  b = 1;

	printf("a=%lf b=%d\n", a, b);

	return 0;
}

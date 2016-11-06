#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	double a, b ,t;
	printf("Please enter two numbers >>>\n");
	scanf("%lf %lf", &a, &b);

	if(a > b)
	{
		t = a;
		a = b;
		b = t;
	}

	printf("the sort result is: %lf, %lf \n", a, b);

	return 0;
}

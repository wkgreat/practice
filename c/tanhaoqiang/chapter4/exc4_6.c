#include<stdio.h>

double the_function(double x);

int main(void)
{
	double x, y;
	printf("Please enter a number>>>");
	scanf("%lf", &x);
	y = the_function(x);
	printf("The value of y is: %lf\n", y);
	return 0;
}

double the_function(double x)
{
	double y;
	if(x<1)
	  y = x;
	else if(x<10)
	  y = 2*x-1;
	else
	  y = 3*x - 11;

	return y;
}

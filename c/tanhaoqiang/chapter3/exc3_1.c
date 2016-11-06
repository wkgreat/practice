#include<stdio.h>
#include<math.h>

int func(int year_no);

int main(void)
{
	double p;
	p = func(10);
	printf("the result is: %lf", p);
	return 0;
}

int func(int year_no)
{
	return pow((1+0.09), year_no);
}

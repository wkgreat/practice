#include<stdio.h>
#include"head1.h"

int main(void)
{
	double a=10;
	double b=20;

	printf("add: %lf\n", wk_add(a,b));
	printf("minus: %lf\n", wk_minus(a,b));
	printf("product: %lf\n", wk_product(a,b));
	printf("deduct: %lf\n", wk_deduct(a,b));

	return 0;
}

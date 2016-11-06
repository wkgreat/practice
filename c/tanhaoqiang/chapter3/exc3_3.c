#include<stdio.h>
#include<math.h>

int main(void)
{
	double d = 300000, p = 6000;
	double r = 0.01;
	double m;
	m = (log(p/(p-d*r))/log(1+r));
	printf("The result is: %.2lf\n", m);
	return 0;
}

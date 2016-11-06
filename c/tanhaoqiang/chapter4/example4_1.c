#include<stdio.h>
#include<math.h>

/*第四章 例4.1 计算二元一次方程*/

int func(double a, double b, double c);

int main(void)
{
	double a, b, c;
	printf("Please enter three coefficients>>>\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	func(a, b, c);
	return 0;
}

int func(double a, double b, double c)
{
	double disc = pow(b,2)-4*a*c;
	double p, q, x1, x2;

	if(disc < 0)
	  printf("This equation hasn't real roots");
	else
	{
		p = -b/(2.0*a);
		q = sqrt(disc)/(2.0*a);
		x1 = p+q;
		x2 = p-q;
		printf("real roots: x1=%lf, x2=%lf\n", x1, x2);
	}
	return 0;
}

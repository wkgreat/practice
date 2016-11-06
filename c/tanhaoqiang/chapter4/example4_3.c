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
	double a, b, c, t;
	printf("Please enter three numbers >>> \n");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if(b<a)
	{
		t = b;
		b = a;
		a = t;
	}
	if(c<b)
	{
		t = c;
		c = b;
		b = t;
	}
	if(b<a)
	{
		t = b;
		b = a;
		a = t;
	}

	printf("The result is: %lf, %lf, %lf\n", a, b, c);
}

int book(void)
{
	float a, b, c, t;
	scanf("%f,%f,%f", &a, &b, &c);
	if(a>b)
	{
		t = a;
		a = b;
		b = t;
	}
	if(a>c)
	{
		t = a;
		a = c;
		c = t;
	}
	if(b>c)
	{
		t = b;
		b = c;
		c = t;
	}
	printf("%5.2f, %5.2f, %5.2f\n", a, b, c);
}

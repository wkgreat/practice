#include<stdio.h>
#include<math.h>

int mine(void);
int book(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	int a=1, sign=-1;
	double result=0, term;
	while(1)
	{
		term = 1.0/a;
		sign*=-1;
		if(fabs(term)<1e-6) break;
		result+=sign*term;
		a+=2;
	}
	printf("The result is: %lf\n", result*4);
	return 0;
}

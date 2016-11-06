#include<stdio.h>

int main(void)
{
	int sign = -1;
	double sum=0;
	for(int i=1; i<=100; ++i)
	{
		sign = -sign; //可以使用负号 而不需要 sign *= -1
		sum += (sign*1/i); 
		printf("%d*1/%d\n", sign, i);
	}

	printf("the result is:%f\n", sum);
	return 0;
}

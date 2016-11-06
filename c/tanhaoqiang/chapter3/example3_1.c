#include<stdio.h>

/*将华氏温度转换成摄氏温度*/

int f_to_c(double f);

int main(void)
{
	double f = 64;
	double c = f_to_c(f);
	printf("%f\n", c);
	return 0;
}

int f_to_c(double f)
{
	return(5.0/9*(f-32)); //is 5.0 not 5
}

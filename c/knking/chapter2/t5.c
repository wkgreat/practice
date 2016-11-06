#include<stdio.h>
#include<math.h>

int main(void)
{
	int x;
	int result;
	printf("Please enter the value of x: ");
	scanf("%d", &x);
	result = 3*pow(x,5)+2*pow(x,4)-5*pow(x,3)-sqrt(x)+7*x-6;
	printf("The result is: %d\n", result);
	return 0;
}

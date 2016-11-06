#include<stdio.h>

int main(void)
{
	float amount, added;
	printf("Enter an amount: ");
	scanf("%f", &amount);
	added = amount*(1+5/100.0);
	printf("With tax added: %f\n", added);
	return 0;
}

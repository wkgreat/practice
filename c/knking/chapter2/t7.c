#include<stdio.h>

int main(void)
{
	float amount;
	int n20, n10, n5, n1;
	float remainder;

	printf("Enter a dollar amount: ");
	scanf("%f", &amount);
	remainder = amount;
	n20 = (int)(remainder/20);
	remainder = remainder - n20*20;
	n10 = (int)(remainder/10);
	remainder = remainder - n10*10;
	n5 = (int)(remainder/5);
	remainder = remainder - n5*5;
	n1 = (int)(remainder);
	printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", n20, n10, n5, n1);
	
	return 0;
}

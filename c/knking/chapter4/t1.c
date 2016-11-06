#include<stdio.h>

int main(void)
{
	int n;
	int a, b;
	printf("Enter a two-digit number: ");
	scanf("%d", &n);
	n = n%10*10+n/10;
	printf("The reversal is: %d\n", n);

	printf("\nEnter a two-digit number: ");
	scanf("%1d%1d", &a, &b);
	printf("The reversal is: %d%d\n", b, a);
	return 0;
}

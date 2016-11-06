#include<stdio.h>

int main(void)
{
	int n;
	printf("Enter a three-digit number: ");
	scanf("%d", &n);
	n = n%100%10*100 + n%100/10*10 + n/100;
	printf("%d\n", n);
	return 0;
}

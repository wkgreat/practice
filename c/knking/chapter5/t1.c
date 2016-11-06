#include<stdio.h>

int main(void)
{
	int a, n=1;
	printf("Enter a number: ");
	scanf("%d", &a);
	while(a/=10) n++;
	printf("The number has %d digits\n", n);
	
	return 0;
}

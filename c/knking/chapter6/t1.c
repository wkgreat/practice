#include<stdio.h>

int main(void)
{
	float n, a;
	printf("Enter a number: ");
	scanf("%f", &a);
	if(!a) return 0;
	for(;;)
	{
		printf("Enter a number: ");
		scanf("%f", &n);
		if(!n) break;
		if(n>a) a=n;
	}
	printf("The largest number entered was %f\n", a);
	return 0;
}

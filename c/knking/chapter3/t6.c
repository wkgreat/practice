#include<stdio.h>

void fraction_add(void);
int main(void)
{
	fraction_add();
	return 0;
}

void fraction_add(void)
{
	float a1, a2, b1, b2;
	printf("Enter two fractions separated by a plus sign: ");
	scanf("%f/%f+%f/%f", &a1, &a2, &b1, &b2);
	printf("The sum is %f\n", a1/a2+b1/b2);
}

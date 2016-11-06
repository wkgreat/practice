#include<stdio.h>

int main(void)
{
	int a, b, t, m, n;
	printf("Enter a fraction: ");
	scanf("%d/%d", &a, &b);
	m=a;
	n=b;
	while(n)
	{
		t=n;
		n=m%n;
		m=t;
	}
	printf("In lowest terms: %d/%d\n", a/m, b/m);
}

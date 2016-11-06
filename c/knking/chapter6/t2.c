#include<stdio.h>

int main(void)
{
	int m, n, t;
	printf("Enter two integers: ");
	scanf("%d%d", &m, &n);

	while(n)
	{
		t=n;
		n=m%n;
		m=t;
	}

	printf("Greatest common divisor: %d\n", m);
}

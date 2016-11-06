#include<stdio.h>
/*最大公约数 gcd 最小公倍数 lcm*/
int gcd(int, int);
int lcm(int, int);
int main(viod)
{
	int a, b;
	printf("Please enter two integer>>>");
	scanf("%d%d", &a, &b);
	printf("gcd=%d lcm=%d\n", gcd(a,b),lcm(a,b));
	printf("\n");return 0;
}

int gcd(int a, int b)
{
	int i,j=0;
	for(i=1;i<=a && i<=b;i++)
	{
		if((a%i == 0) && (b%i == 0))
		  j=i;
	}
	return j;
}

int lcm(int a, int b)
{
	int i;
	i = a>b?a:b;
	while(!(i%a == 0 && i%b == 0))
	{
		++i;
	}
	return i;
}

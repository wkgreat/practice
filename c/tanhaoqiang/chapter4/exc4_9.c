#include<stdio.h>

int main(void)
{
	int a, n=0, d, nixushu=0;
	do
	{
		printf("Please enter a number that no more than 5 digits>>>");
		scanf("%d", &a);
	}while(a<=0 || a > 99999);

	while(1)
	{
		n++;
		d = a%10;
		nixushu = (nixushu*10+d);
		printf("n=%d d=%d nixushu=%d\n", n, d, nixushu);
		if(!(a/=10)) break;
	}
	return 0;
}

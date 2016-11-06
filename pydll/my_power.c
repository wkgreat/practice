#include<stdio.h>
/*¼ÆËãÃİ*/
int my_power(int base, int n);

int my_power(int base, int n)
{
	int i;
	int result = 1;
	for(i = 1; i <= n; ++i)
	{
		result *= base;
	}
	return result;
}

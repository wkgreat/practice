#include<stdio.h>

/*测试无符号整型 能否存负数*/

int main(void)
{
	unsigned short price = -1;
	printf("%d\n", price);
	printf("%u\n", price);
	return 0;
}

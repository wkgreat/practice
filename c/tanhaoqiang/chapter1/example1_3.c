#include<stdio.h>

/*the main function*/
int main(void)
{
	int max(int x, int y); //对调用函数 max 的声明
	int a, b, c;
	scanf("%d,%d", &a, &b);
	c = max(a, b);
	printf("max=%d\n", c);
	return 0;
}


int max(int x, int y)
{
	int z;
	if(x > y)z = x;
	else z = y;
	return(z);
}


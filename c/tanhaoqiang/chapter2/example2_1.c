#include<stdio.h>

/*�ڶ��� ����2.1*/
/* �� 1*2*3*4*5 ��ֵ */

int jiecheng(int n);

int main(void)
{
	int n;
	printf("Please enter a integer to calcuter its factorial >>>");
	scanf("%d", &n);
	printf("the factorial is: %d\n", jiecheng(5));
	return 0;
}

int jiecheng(int n)
{
	int result=1;
	for(int i=1; i<=n; ++i)
		result *= i;

	return result;
}


#include<stdio.h>

int test1(void);
int test2(void);

int main(void)
{
//	test1();
	test2();
	return 0;
}

int test1(void)
{
	char a[10];
	scanf("%s", a);
	printf("\n%s\n", a);
}

int test2(void)
{
	int a[10][10] = {1};
	int i, j;
	for(i=0;i<10;i++)
	  for(j=0;j<10;j++)
		printf("%d ", a[i][j]);
	return 0;
}

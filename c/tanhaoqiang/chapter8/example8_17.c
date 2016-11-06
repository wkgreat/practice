#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	printf("\n");return 0;
}

int mine(void)
{
	char a[15] = "Hello,world!";
	char *p=a;
	printf("%s", p);
	return 0;
}

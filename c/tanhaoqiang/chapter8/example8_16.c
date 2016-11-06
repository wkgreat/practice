#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	printf("\n");return 0;
}

int mine(void)
{
	char a[15] = "Hello, world!";
	printf("%s\n", a);
	printf("%c\n", a[7]);
	a[8] = 'T';
	printf("%s\n", a);
	return 0;
}

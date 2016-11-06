#include<stdio.h>
#include<stdlib.h>

int mine(void);

int main(void)
{
	mine();
	printf("\n");return 0;
}

int mine(void)
{
	char a[15] = "Hello, world!";
	char *ap = a;
	char *b = (char *)malloc(15*sizeof(char));
	char *bp = b;
	while(*bp++=*ap++);
	printf("%s\n", b);
	return 0;
}

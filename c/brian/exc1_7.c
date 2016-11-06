#include<stdio.h>

int main()
{
	char c;
	while((c = getchar()) != EOF)
		putchar(c);
	putchar('\n');
	printf("%d\n", c);
	return 0;
}

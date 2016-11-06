#include<stdio.h>

int get_max(int a, int b, int c);

int main(void)
{
	int a, b, c, the_max;
	printf("Please enter three numbers>>>");
	scanf("%d,%d,%d", &a, &b, &c);
	the_max = get_max(a, b, c);
	printf("The max number is: %d\n", the_max);
	return 0;
}

int get_max(int a, int b, int c)
{
	int t;
	t = (a>b)?a:b;
	t = (t>c)?t:c;
	return t;
}


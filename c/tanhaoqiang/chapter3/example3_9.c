#include<stdio.h>

int main(void)
{
	f1();
//	f2();
	return 0;
}

int f1(void)
{

	char a, b, c;
	a = getchar();
	putchar(a);
	b = getchar();
	c = getchar();

//	putchar(a);
	putchar(b);
	putchar(c);
	putchar('\n');
	return 0;
}

int f2(void)
{
	putchar(getchar());
	putchar(getchar());
	putchar(getchar());
	putchar('\n');
	return 0;
}

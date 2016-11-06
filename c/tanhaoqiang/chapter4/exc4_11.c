#include<stdio.h>

int sort(int a, int b, int c, int d);

int main(void)
{
	int a, b, c, d;
	printf("Please enter four numbers>>>");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	sort(a, b, c, d);
	return 0;
}

int sort(int a, int b, int c, int d)
{
	int t;
	if(a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	if(a>c)
	{
		t=a;
		a=c;
		c=t;
	}
	if(a>d)
	{
		t=a;
		a=d;
		d=t;
	}
	if(b>c)
	{
		t=b;
		b=c;
		c=t;
	}
	if(b>d)
	{
		t=b;
		b=d;
		d=t;
	}
	if(c>d)
	{
		t=c;
		c=d;
		d=t;
	}

	printf("The result is:%d,%d,%d,%d\n", a, b, c, d);

}

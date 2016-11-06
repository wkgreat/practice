#include<stdio.h>
#include<stdlib.h>

typedef struct str
{
	int no;
	char name[10];
} *pstr;

int test1();
int test2();

int main(void)
{
//	test1();
	test2();
	return 0;
}

int test1()
{
//	str s;
//	printf("%d", s.no);
	return 0;
}

int test2()
{
	int a = 1;
	int *pa = &a;
	printf("%d\n",a);
	free(pa);
	printf("%d",pa);
	return 0;
}

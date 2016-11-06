#include<stdio.h>
#include<stdlib.h>

int test1(void);

int main(void)
{
	test1();
	return 0;
}

int test1(void)
{
	int *p = (int *)malloc(5*sizeof(int));
	int i;
	for(i=0;i<5;i++)
	  *(p+i) = i;
	p = realloc(p,10*sizeof(int));
	for(i=0;i<10;i++)
	  printf("%d ", *(p+i));
	p = realloc(p,3*sizeof(int));
	printf("\n");
	for(i=0;i<10;i++)
	  printf("%d ", *(p+i));
	return 0;
}

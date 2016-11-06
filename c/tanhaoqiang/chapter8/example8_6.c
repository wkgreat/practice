#include<stdio.h>
#include<stdlib.h>

int mine(void);

int main(void)
{
	mine();
	printf("\n");
	return 0;
}

int mine(void)
{
	int *p = malloc(10*sizeof(int));
	int i;
	for(i=0;i<10;i++)
	  *(p+i) = i;
	for(i=0;i<10;i++)
	  printf("%d ",p[i]);
	return 0;
}

#include<stdio.h>

int main(void)
{
	int i, j, k;
	i=3; j=4; k=5;
	printf("%d\n", i<j || ++j<k);
	printf("%d %d %d\n", i, j, k);
	return 0;
}

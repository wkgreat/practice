#include<stdio.h>

int mine(void);
int reverse(int *, int );

int main(void)
{
	mine();
	printf("\n");return 0;
}

int mine(void)
{
	int a[5] = {1,2,3,4,5};
	int i;
	for(i=0;i<5;i++)
	  printf("%d ", *(a+i));
	printf("\n");
	reverse(a,5);
	for(i=0;i<5;i++)
	  printf("%d ",*(a+i));
	printf("\n");
	return 0;
}

int reverse(int *a, int n)
{
	int *i=a, *j=a+n-1;
	int temp;
	while(i<=j)
	{
		temp = *i;
		*i = *j;
		*j = temp;
		i++;j--;
	}
	return 0;
}

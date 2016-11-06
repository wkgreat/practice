#include<stdio.h>

int bubble_sort(int a[], int n);

int main(void)
{
	int a[6] = {5,7,4,2,8,3};
	bubble_sort(a, 6);
	int i;
	for(i=0;i<6;i++)
	  printf("%d ", a[i]);
	printf("\n");return 0;
}

int bubble_sort(int a[], int n)
{
	int i,j,change=1,temp;
	for(i=n-1;i>=1 && change;i--)
	{
		change = 0;
		for(j=0;j<i;j++)
		  if(a[j]>a[j+1])
		  {
			  temp = a[j];
			  a[j] = a[j+1];
			  a[j+1] = temp;
			  change = 1;
		  }
	}
	return 0;
}//bubble_sort

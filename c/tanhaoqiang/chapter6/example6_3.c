#include<stdio.h>

int sort1(int[], int);

int main(void)
{
	int i;
	int a[5] = {3,2,1,4,6};
	sort1(a,5);
	for(i=0;i<5;i++)
	  printf("%d ", a[i]);
	printf("\n");
	return 0;
}

int sort1(int a[], int n)
{
	int i, j, t;
	for(i=0;i<n;i++)
	  for(j=i;j<n;j++)
		if(a[j] < a[i])
		{
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	return 0;
}

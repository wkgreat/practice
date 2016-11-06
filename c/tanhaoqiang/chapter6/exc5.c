#include<stdio.h>

int mine(void);
int reverse(int *, int n);

int main(void)
{
	mine();
	printf("\n");return 0;
}

int mine(void)
{
	int a[10];
	int i;
	printf("Please enter ten numbers>>>\n");
	for(i=0;i<10;++i)
		scanf("%d",a+i);
	printf("The value of the numbric group is:");
	for(i=0;i<10;i++)
	  printf("%d ", *(a+i));
	printf("\nThe result is:\n");
	reverse(a, 10);
	for(i=0;i<10;i++)
	  printf("%d ", *(a+i));
	return 0;

}

int reverse(int *a, int n)
{
	int i, j, temp;
	for(i=0,j=n-1;i<j;i++,j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	return 0;
}

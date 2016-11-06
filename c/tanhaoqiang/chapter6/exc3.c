#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	printf("\n");return 0;
}

int mine(void)
{
	int a[3][3];
	int i, j, sum1=0, sum2=0;
	for(i=0;i<3;++i)
	  for(j=0;j<3;++j)
	  {
		scanf("%d", &a[i][j]);
	  }
	for(i=0;i<3;++i)
	  for(j=0;j<3;++j)
	  {
		  if(i==j) sum1+=a[i][j];
		  if(2-i==j) sum2+=a[i][j];
	  }
	for(i=0;i<3;++i)
	{printf("\n");
	  for(j=0;j<3;++j)
	  {
		  printf("%5d", a[i][j]);
	  }
	}
	printf("\nsum1=%d sum2=%d", sum1, sum2);
	return 0;
}

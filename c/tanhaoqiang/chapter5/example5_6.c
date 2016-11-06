#include<stdio.h>

int mine(void);
int book(void);

int main(void)
{
	mine();
	printf("\n===book===\n");
	book();
	return 0;
}

int mine(void)
{
	int i, j, n;
	for(i=1;i<5;++i)
	{
		n=0;
		for(j=1;j<=5;++j)
		{
			n+=i;
			printf("%d	", n);
		}
		printf("\n");
	}

	return 0;
}

int book(void)
{
	int i, j, n=0;
	for(i=1;i<=4;i++)
	  for(j=1;j<=5;j++,n++)
	  {
		  if(n%5==0) printf("\n");
		  printf("%d\t", i*j);
	  }
	printf("\n");
	return 0;
}

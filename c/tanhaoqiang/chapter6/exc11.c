#include<stdio.h>

int main(void)
{
	char a[5][10];
	int i, j;
	for(i=0;i<5;i++)
	  for(j=0;j<10;j++)
	  {
		  if(j>=i && j<i+5)
			a[i][j] = '*';
		  else
			a[i][j] = ' ';
	  }

	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		  printf("%c ",a[i][j]);
		printf("\n");
	}


	
	printf("\n");return 0;
}

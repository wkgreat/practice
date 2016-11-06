#include<stdio.h>
#include<stdlib.h>

int yanghui( int );
int *create(int,int);

int main(void)
{
	int row;
	printf("Please enter the row>>>\n");
	scanf("%d",&row);
	yanghui(row);
	printf("\n"); return 0;
}

int yanghui(int row)
{//row * row
	int column;
	int *p;
	int i, j;
	column = row;
	p = create(row,column);
	printf("row=%d, column=%d\n", row, column);
	*p = *(p+(1*column+0)) = *(p+(1*column+1)) = 1;
	for(i=2;i<row;i++)
	  for(j=0;j<=i;j++)
	  {
		  *(p+(i*column+j)) = *(p+((i-1)*column+(j))) + *(p+((i-1)*column+(j-1)));
	  }

	for(i=0;i<row;i++)
	{
	  for(j=0;j<=i;j++)
	  {
		  printf("%d\t", *(p+(column*i+j)));
	  }
	  printf("\n");
	}

	return 0;
}

int *create(int row, int column)
{
	int *p;
	p = (int *)malloc(row*column*sizeof(int));
	return p;
}

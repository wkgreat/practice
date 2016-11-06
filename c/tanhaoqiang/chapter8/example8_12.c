#include<stdio.h>
#include<stdlib.h>

int mine(void);
int print2dmatrix(int (*)[4], int, int);
int main(void)
{
	mine();
	printf("\n");return 0;
}

int mine(void)
{
	int (*a)[4] = (int (*)[4])malloc(3*4*sizeof(int));
	int i, j;
	for(i=0;i<3;i++)
	  for(j=0;j<4;j++)
		a[i][j] = i+j;
	print2dmatrix(a,3,4);
	free(a);
	return 0;
}

int print2dmatrix(int (*a)[4], int row, int column)
{
	int i, j;
	for(i=0;i<row;i++)
	{
		printf("\n");
		for(j=0;j<column;j++)
		{
			printf("%d ",*(*(a+i)+j));
		}
	}
	return 0;
}

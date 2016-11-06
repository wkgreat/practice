#include<stdio.h>

int saddle_point(int a[][3], int row, int column);

int main(void)
{
	int a[3][3]={0,7,0,1,5,2,0,7,0};
	saddle_point(a,3,3);
	printf("\n");return 0;
}

int saddle_point(int a[][3], int row, int column)
{
	int i, j, k;
	int b[3][3]={0};
	int c[3][3]={0};
	for(i=0;i<row;i++)
	{
		k=0;
		for(j=0;j<column;j++)
			if(a[i][j] > a[i][k]) k=j;
		for(j=0;j<column;j++)
		  if(a[i][j] == a[i][k])
			b[i][j] = 1;
	}
	printf("b");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
			printf("%3d ",b[i][j]);
	}
	printf("\n");
	for(i=0;i<column;i++)
	{
		k=0;
		for(j=0;j<row;j++)
		  if(a[j][i] < a[k][i]) k=j;
		for(j=0;j<row;j++)
		  if(a[j][i] == a[k][i])
			c[j][i] = 1;
	}
	printf("c:\n");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
			printf("%3d ",c[i][j]);
	}
	printf("\n");
	for(i=0;i<row;i++)
	{
	  for(j=0;j<column;j++)
		if(b[i][j] && c[i][j])
		  b[i][j] = 1;
		else
		  b[i][j] = 0;
	}
	printf("\n");
	for(i=0;i<row;i++)
	{
	  for(j=0;j<column;j++)
		printf("%3d ", b[i][j]);
	  printf("\n");
	}

	return 0;

}

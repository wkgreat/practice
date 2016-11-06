#include<stdio.h>
int countPatch(int(*)[10], int rows, int cols);
int spand(int(*)[10],int,int,int,int);

int main()
{
	int m[10][10] = 
	{
		{1,0,0,0,0,0,0,0,1,0},
		{0,0,0,0,0,0,0,1,1,0},
		{0,1,1,0,0,0,0,1,0,0},
		{0,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,0,0,0},
		{1,0,0,0,0,1,1,0,1,0},
		{0,0,0,1,1,0,0,0,1,0},
		{0,0,0,1,1,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,0},
	};

	printf("count home: %d\n", countPatch(m,10,10));
	return 0;
}

int countPatch(int(*m)[10], int rows, int cols)
{
	int i,j;
	int c=0;
	for(i=0; i<rows; ++i)
		for(j=0;j<cols; ++j)
		{
			if( m[i][j] == 1)
			{
				++c;
				spand(m,i,j,rows,cols);
			}
		}

	return c;
}

int spand(int(*m)[10], int x, int y, int rows, int cols)
{
	if( x<0 || x>=rows || y<0 || y>=cols ) return 0;
	if( m[x][y] == 0 ) return 0;
	if( m[x][y] == 1 )
	{
		m[x][y] = 0;
		spand(m,x-1,y,rows,cols);
		spand(m,x+1,y,rows,cols);
		spand(m,x,y-1,rows,cols);
		spand(m,x,y+1,rows,cols);
	}
	return 0;
}


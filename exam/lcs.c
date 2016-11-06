/*lcs: longest common subsequence*/
#define MAXLENGTH 1000
#include<stdio.h>
#include<stdlib.h>

int lcsLength(char*, char*, int**, int, int);
int strLength(char*);
int** malloc2DInt(int height, int width);
int getValue(int**,int,int);
int print2DInt(int**, int, int);

int main(void)
{
	char* a = "aaaaaaa12345678aaaa9a";
	char* b = "bb12345678bbbbbb9bbbbbbbbbb";

	int lena = strLength(a);
	int lenb = strLength(b);
	printf("alen:%d blen:%d\n", strLength(a), strLength(b));
	int** c = malloc2DInt(strLength(a), strLength(b));
	

	int i,j;

	for(i=0;i<strLength(a);++i)
	{
		for(j=0;j<strLength(b);++j)
			*(*(c+i)+j) = -1;
	}
	
	lcsLength(a,b,c,strLength(a)-1,strLength(b)-1);

	print2DInt(c, lena, lenb);
	return 0;

}

int print2DInt(int**c, int lena, int lenb)
{
	int i,j;
	for(i=0;i<lena;++i)
	{
		for(j=0;j<lenb;++j)
			printf("%d ", *(*(c+i)+j));
		printf("\n");
	}
	return 0;
}

int lcsLength(char* pa, char* pb, int**c, int i, int j)
{
	int left;
	int right;
	if(i<0 || j<0) return 0;
	if(getValue(c,i,j) >= 0) return getValue(c,i,j);
	printf("%d %d\n", i, j);
	if(*(pa+i) == *(pb+j))
	{
		return *(*(c+i)+j)=(1+lcsLength(pa, pb, c, i-1, j-1));
	}
	else
	{
		left = lcsLength(pa,pb,c,i,j-1);
		right = lcsLength(pa,pb,c,i-1,j);
		return *(*(c+i)+j) = (left>right)?left:right;
		//return *(*(c+i)+j);
	}

	return 0;
}

int strLength(char* pa)
{
	int i=0;
	char* p;
	for(p=pa;*p;++p) ++i;
	return i;
}

int** malloc2DInt(int height, int width)
{
	
	int **c = (int**)malloc(sizeof(int*)*height);
	int i;
	for(i=0;i<height;++i)
	{
		*(c+i) = (int*)malloc(sizeof(int)*width);
	}
	return c;
}

int getValue(int** c, int i, int j)
{
	return *(*(c+i)+j);
}

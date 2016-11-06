/*lcs: longest common subsequence*/
#define MAXLENGTH 1000
#define max(a,b) ((a)>(b)?(a):(b))
#include<stdio.h>
#include<stdlib.h>

int lcsLength(char*, char*, int**, int, int);
int strLength(char*);
int** malloc2DInt(int height, int width);

int main(void)
{
	char* a = "qwertwangkepje";
	char* b = "jjjooolllwangeedd";

	printf("alen:%d blen:%d\n", strLength(a), strLength(b));
	int** c = malloc2DInt(strLength(a), strLength(b));
	
	lcsLength(a,b,c,strLength(a)-1,strLength(b)-1);
	int i,j;
	for(i=0;i<strLength(a);++i)
	{
		for(j=0;j<strLength(b);++j)
			printf("%d ", *(*(c+i)+j));
		printf("\n");
	}
	return 0;
}

int lcsLength(char* pa, char* pb, int**c, int i, int j)
{
	if(i<0 || j<0) return 0;
	printf("%d %d\n", i, j);
	if(*(pa+i) == *(pb+j))
	{
		return *(*(c+i)+j)=(1+lcsLength(pa, pb, c, i-1, j-1));
	}
	else
	{ 
		return *(*(c+i)+j)=max(lcsLength(pa,pb,c,i-1,j),lcsLength(pa,pb,c,i,j-1));
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



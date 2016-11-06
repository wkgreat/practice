#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./raster.h"


double interpolate(Raster *raster, double x, double y, int xWindowRadius, int yWindowRadius);
int getIndex(int rowNo, int colNo, int nCol);
int getRow(Raster *raster, double y);
int getCol(Raster *raster, double x);
double x_col(Raster *raster , int colNo);
double y_row(Raster *raster, int rowNo);

int main(void)
{
	Raster *raster;
	raster->nRow = 10;
	raster->nCol = 10;
	(raster->origin).x=0;
	(raster->origin).y=0;
	raster->xRes = 1.0;
	raster->yRes = 1.0;

	raster->matrix = (double*)malloc(sizeof(double)*100);
	int i;
	for(i=0;i<100;++i)
	{
		*((raster->matrix)+i) = 5;
	}
	
	double result = interpolate(raster, 2.7,2.7,1,1);
	printf("Result:%lf\n", result);

	return 0;
}

double interpolate(Raster *raster, double x, double y, int xWindowRadius, int yWindowRadius)
{
	/*
	      ^y
	      |---------|
	      |(0,0)	|
		  |			|
		  |height	|
		  | 		|
	   ---|---------|-->x
		  |	 width

	 */

	raster->xmax = (raster->origin).x+(raster->nCol)*(raster->xRes);
	raster->ymax = (raster->origin).y+(raster->nRow)*(raster->yRes);

	double xmax = raster->xmax;
	double ymax = raster->ymax;
	double x0 = (raster->origin).x;
	double y0 = (raster->origin).y;

	double xRes = raster->xRes;
	double yRes = raster->yRes;
	double xp = x_col(raster, getCol(raster,x))-(xWindowRadius-1)*xRes;
	double xpLimit = xp+(xWindowRadius*2-1)+xRes/10;
	double yq = y_row(raster, getRow(raster,y))-(yWindowRadius-1)*yRes;
	double yqLimit = yq+(yWindowRadius*2-1)+xRes/10;

	double ddd = 1.0/10000;

	double i,j;
	double k,l;
	double ppX, ppY, ss;
	double z;

	int theIndex;
	
	ss=0;
	for(i=xp; i<=xpLimit; i+=xRes)
	{
		if(i<x0-ddd || i>xmax+ddd) continue;
		for(j=yq; j<=yqLimit; j+=yRes)
		{
			if(j<y0-ddd || j>ymax+ddd) continue;
			ppX=1;
			for(k=xp; k<=xpLimit; k+=xRes)
			{
				if(k<x0-ddd || k>xmax+ddd) continue;
				if(abs(k-i)<ddd) continue;//k==i
				ppX*=((x-k)/(i-k));
			}

			ppY=1;
			for(l=yq; l<=yqLimit; l+=yRes)
			{
				if(l<y0-ddd || l>ymax+ddd) continue;
				if(abs(l-j)<ddd) continue;//l==j
				ppY*=((y-l)/(j-l));
			}

			theIndex = getIndex(getRow(raster, j), getCol(raster, i), raster->nCol);
			z = (raster->matrix)[theIndex];
			ss+=ppX*ppY*z;;
		}
	}

	return ss;
	
}

int getIndex(int rowNo, int colNo, int nCol)
{
	return rowNo*nCol+colNo;
}


int getRow(Raster *raster, double y)
{
	double y0 = (raster->origin).y;
	double yRes = raster->yRes;
	int nRow = raster->nRow;
	int rowNo = (nRow-1)-(int)(( y-(y0+yRes/2.0) )/yRes + 0.5); //need round off
	return rowNo;
}

int getCol(Raster *raster, double x)
{
	double x0 = (raster->origin).x;
	double xRes = raster->xRes;
	int colNo = (int)( ( x-(x0+xRes/2.0) )/xRes + 0.5 ); //need round off
	return colNo;
}

double x_col(Raster *raster, int colNo)
{
	double x0 = (raster->origin).x;
	double xRes = raster->xRes;
	return (colNo+1)*xRes+x0-xRes/2.0;
}
double y_row(Raster *raster, int rowNo)
{
	int nRow = raster->nRow;
	double y0 = (raster->origin).y;
	double yRes = raster->yRes;
	return (nRow-rowNo)*yRes+y0-yRes/2.0;
}

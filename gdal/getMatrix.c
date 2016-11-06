/****************************************
 |	Task: get the data matrix of Raster |
 |	Writer: Wang Ke                     |
 |	Date: 2015/01/20                    |
 ****************************************/
#include<stdio.h>
#include<math.h>
#include"gdal.h"
#include"cpl_conv.h"


float* getMatrix(GDALRasterBandH, int, int*, int*);
float* copyMatrix(float*, int, int);
float* getSlope(float* matrix, int xSize, int ySize, float xRes, float yRes, float zFactor);
float getMatrixValue(float *, int, int, int);
int* getRowColumnNo(int, int, int);

int main(void)
{
	GDALAllRegister();

	GDALDriverH hDriver = GDALGetDriverByName( "GTiff" );

	GDALDatasetH hDataset;
	GDALRasterBandH hBand;
	double adfGeoTransform[6];
	float xRes, yRes;
	int xSize, ySize;

	GDALDatasetH slopeRaster;
	GDALRasterBandH slopeBand;

	hDataset = GDALOpen("dem.tif", GA_ReadOnly);
	if(hDataset == NULL)
	{
		printf("Input dataset is NULL!\n");
		exit(1);
	}

	if(GDALGetGeoTransform(hDataset, adfGeoTransform) == CE_None)
	{
		xRes = abs(adfGeoTransform[1]);
		yRes = abs(adfGeoTransform[5]);
	}

	printf("xRes:%.1f, yRes:%.1f\n", xRes, yRes);

	
	float *matrix = getMatrix(hDataset,1,&xSize,&ySize);
	float *slopeMatrix = getSlope(matrix, xSize, ySize, xRes, yRes, 1);

	slopeRaster = GDALCreateCopy( hDriver, "./slope.tif", hDataset, FALSE, NULL, NULL, NULL);
	slopeBand = GDALGetRasterBand(slopeRaster, 1);

	GDALRasterIO( slopeBand,GF_Write,0,0,xSize,ySize,slopeMatrix,xSize,ySize,GDT_Float32,0,0 );

	GDALClose(hDataset);
	GDALClose(slopeRaster);
	return 0;
}

/******************************************************************
 |	Function: getMatrix											  |
 |	Parameter: 													  |
 |		hDataset: The Raster Dataset							  |
 |		bandNo: Which band of the raster want to get data matrix  |
 |		pxSize: output the raster x direction size(width)		  |
 |		pySize: output the raster y direction size(height)        |
 |																  |
 ******************************************************************/

float* getMatrix(GDALDatasetH hDataset, int bandNo, int* pxSize, int* pySize)
{
	int xSize,ySize;
	GDALRasterBandH hBand = GDALGetRasterBand(hDataset, bandNo);
	xSize = GDALGetRasterXSize(hDataset);
	ySize = GDALGetRasterYSize(hDataset);
	*pxSize = xSize;
	*pySize = ySize;

	float *matrix = (float *)CPLMalloc(sizeof(float)*xSize*ySize);

	GDALRasterIO(hBand, GF_Read, 0,0,xSize,ySize,matrix,xSize,ySize,GDT_Float32,0,0);

	return matrix;
}

float* copyMatrix(float *matrix, int xSize, int ySize)
{
	float *matrixCopy = (float*)CPLMalloc(sizeof(float)*xSize*ySize);
	int i;
	for(i=0;i<xSize*ySize;++i)
		*(matrixCopy+i) = *(matrix+i);
	return matrixCopy;
}

float* getSlope(float* matrix, int xSize, int ySize, float xRes, float yRes, float zFactor)
{
	int i;
	float upLeft,	up,		upRight;
	float left,				right;
	float downLeft,	down,	downRight;
	float* slopeMatrix = copyMatrix(matrix, xSize, ySize);
	float dx, dy;
	float ratioSlope, degreeSlope;

	for(i=0;i<xSize*ySize;++i)
	{
		
		upLeft = getMatrixValue(matrix, i-xSize-1, xSize, ySize);
		up = getMatrixValue(matrix, i-xSize, xSize, ySize);
		upRight = getMatrixValue(matrix, i-xSize+1, xSize, ySize);
		left = getMatrixValue(matrix, i-1, xSize, ySize);
		right = getMatrixValue(matrix, i+1, xSize, ySize);
		downLeft = getMatrixValue(matrix, i+xSize-1, xSize, ySize);
		down = getMatrixValue(matrix, i+xSize, xSize, ySize);
		downRight = getMatrixValue(matrix, i+xSize+1, xSize, ySize);

		dx = ((upRight+right*2+downRight) - (upLeft+left*2+downLeft)) * zFactor / (8*xRes);
		dy = ((downLeft+down*2+downRight) - (upLeft+up*2+upRight)) * zFactor / (8*yRes);

		ratioSlope = sqrt(dx*dx+dy*dy);
		degreeSlope = atan(ratioSlope)*57.29578;

		slopeMatrix[i] = degreeSlope;
	}
	
	return slopeMatrix;
}

float getMatrixValue(float *matrix, int index, int xSize, int ySize)
{
	float value;
	int rowNo, columnNo;
	int *rowColumnNo = getRowColumnNo(index, xSize, ySize);
	rowNo = rowColumnNo[0];
	columnNo = rowColumnNo[1];
	value = (rowNo<0 || rowNo>=ySize || columnNo<0 || columnNo>=xSize)?0:matrix[index];
	return value;
}

int* getRowColumnNo(int index, int xSize, int ySize)
{
	int rowColumnNo[2];
	int rowNo, columnNo;
	rowNo = index/xSize;
	columnNo = index - rowNo*xSize;
	rowColumnNo[0] = rowNo;
	rowColumnNo[1] = columnNo;
	return rowColumnNo;
}


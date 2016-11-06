#include<stdio.h>
#include"gdal.h"
#include"cpl_conv.h"
int main(void)
{
	GDALAllRegister();
	/*Open a file*/
	GDALDatasetH hDataset;
	hDataset = GDALOpen( "./dem.tif", GA_ReadOnly );
	if( hDataset == NULL ) printf("The dataset is NULL!\n");
	/*Getting Dasetset Information*/
	GDALDriverH hDriver;
	double adfGeoTransform[6];
	hDriver = GDALGetDatasetDriver( hDataset );
	printf( "Driver: %s/%s\n",
			GDALGetDriverShortName( hDriver ),
			GDALGetDriverLongName( hDriver ));
	printf("Size is %dx%dx%d\n",
			GDALGetRasterXSize( hDataset ),
			GDALGetRasterYSize( hDataset ),
			GDALGetRasterCount( hDataset ));
	if( GDALGetProjectionRef( hDataset ) != NULL )
		printf("Projection is '%s'\n", GDALGetProjectionRef( hDataset ) );
	if (GDALGetGeoTransform( hDataset, adfGeoTransform ) == CE_None )
	{
		printf("Origin = (%.6f,%.6f)\n",
				adfGeoTransform[0], adfGeoTransform[3]);
		printf( "Pixel Size = (%.6f,%.6f)\n",
				adfGeoTransform[0], adfGeoTransform[5]);
	}
	/*Fetching a Raster Band*/
	GDALRasterBandH hBand;
	int nBlockXSize, nBlockYSize;
	int bGotMin, bGotMax;
	double adfMinMax[2];
	hBand = GDALGetRasterBand( hDataset, 1);
	GDALGetBlockSize( hBand, &nBlockXSize, &nBlockYSize);
	printf( "Block=%dx%d Type=%s, ColorInterp=%s\n",
			nBlockXSize, nBlockYSize,
			GDALGetDataTypeName(GDALGetRasterDataType(hBand)),
			GDALGetColorInterpretationName(
				GDALGetRasterColorInterpretation(hBand)) );
	adfMinMax[0] = GDALGetRasterMinimum( hBand, &bGotMin );
	adfMinMax[1] = GDALGetRasterMaximum( hBand, &bGotMax );
	if( !(bGotMin && bGotMax) )
	{
		GDALComputeRasterMinMax( hBand, TRUE, adfMinMax );
	}
	printf( "Min=%.3fd, Max=%.3f\n", adfMinMax[0], adfMinMax[1]);
	if(GDALGetOverviewCount(hBand) > 0)
		printf( "Band has %d overviews.\n", GDALGetOverviewCount(hBand));
	if( GDALGetRasterColorTable( hBand ) != NULL)
		printf( "Band has a color table with %d entries.\n",
				GDALGetColorEntryCount(
					GDALGetRasterColorTable( hBand)));
	/*Reading Raster Data*/
	float *pafScanline;
	int nXSize = GDALGetRasterBandXSize( hBand );
	pafScanline = (float *)CPLMalloc(sizeof(float)*nXSize);
	GDALRasterIO(hBand, GF_Read, 0, 0, nXSize, 1,
			pafScanline, nXSize, 1, GDT_Float32, 0, 0);
	CPLFree(pafScanline);
	return 0;
}

#include<stdio.h>
#include"gdal.h"
#include"cpl_string.h"
#include"ogr_srs_api.h"

int main(void)
{
	GDALAllRegister();

	char *pszFormat = "GTiff";
	GDALDriverH hDriver = GDALGetDriverByName( pszFormat );
	GDALDatasetH hDstDS, newDS;
	char **papszOptions = NULL;

	hDstDS = GDALCreate( hDriver, "new.tif", 512, 512, 1, GDT_Byte, papszOptions);


	double adfGeoTransform[6] = {444720, 30, 0, 3751320, 0, -30};
	OGRSpatialReferenceH hSRS;
	char *pszSRS_WKT = NULL;
	GDALRasterBandH hBand;
	GByte abyRaster[512*512];

	GDALSetGeoTransform( hDstDS, adfGeoTransform );

	hSRS = OSRNewSpatialReference( NULL );
	OSRSetUTM( hSRS, 11, TRUE );
	OSRSetWellKnownGeogCS( hSRS, "NAD27" );
	OSRExportToWkt( hSRS, &pszSRS_WKT );
	OSRDestroySpatialReference( hSRS );

	GDALSetProjection( hDstDS, pszSRS_WKT );
	CPLFree( pszSRS_WKT );

	hBand = GDALGetRasterBand( hDstDS, 1 );
	GDALRasterIO( hBand, GF_Write, 0, 0, 512, 512, abyRaster, 512, 512, GDT_Byte, 0, 0);

		/*Once we're done, close properly the dataset*/
	GDALClose( hDstDS );

	return 0;
}

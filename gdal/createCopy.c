#include<stdio.h>
#include"gdal.h"
#include"cpl_string.h"

int main(void)
{
	GDALAllRegister();	

	/*Techniques for Creating Files*/
	const char *pszFormat = "GTiff";
	GDALDriverH hDriver = GDALGetDriverByName( pszFormat );
	char ** papszMetadata;

	if( hDriver == NULL)
	{
		printf("hDriver is NULL!\n");
		exit(1);
	}

	papszMetadata = GDALGetMetadata( hDriver, NULL);
	if( CSLFetchBoolean( papszMetadata, GDAL_DCAP_CREATE, FALSE ) )
		printf( "Driver %s supports Create() method.\n", pszFormat);
	if( CSLFetchBoolean( papszMetadata, GDAL_DCAP_CREATECOPY, FALSE ) )
		printf( "Driver %s supports CreateCopy() method.\n", pszFormat);
	
	/*Using CreateCopy()*/
	/*Note that the CreateCopy() method returns a writeable dataset, and that it must be closed peoperly to complete wrting and flushing the dataset to disk.*/
	GDALDatasetH hSrcDS = GDALOpen( "dem.tif", GA_ReadOnly);
	GDALDatasetH hDstDS;

	hDstDS = GDALCreateCopy(hDriver, "demCopy.tif", hSrcDS, FALSE, NULL,NULL,NULL);

		/*Once we're done, close properly the dataset*/
	if( hDstDS != NULL)
	{
		printf("hDstDS is not NULL!\n");
		GDALClose( hDstDS);
	}

	/*A more complex case might invovle passing creation options, and using a predefined progress moniter like this:*/
	char **papszOptions = NULL;

	papszOptions = CSLSetNameValue( papszOptions, "TILED", "YES");
	papszOptions = CSLSetNameValue( papszOptions, "COMPRESS", "PACKBITS");
	hDstDS = GDALCreateCopy( hDriver, "demCopy2.tif", hSrcDS, FALSE, papszOptions, GDALTermProgress, NULL); /* GDALTermProgress can show the progress in the terminal,like0...10...20........100 - done*/

		/*Once we're done, close properly the dataset*/
	if(hDstDS != NULL)
	{
		printf("hDstDS is not NULL!\n");
		GDALClose( hDstDS);
	}
	CSLDestroy( papszOptions );
	GDALClose(hSrcDS);
	
	return 0;
}

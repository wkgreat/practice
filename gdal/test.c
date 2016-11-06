#include<stdio.h>
#include"gdal.h"
#include"cpl_conv.h"

int main(void)
{
	GDALDatasetH hDataset;
	
	GDALAllRegister();

	hDataset = GDALOpen("dem.tif", GA_ReadOnly);
	if( hDataset == NULL )
	{
		printf("hDataset is NULL\n");
	}
	return 0;
}

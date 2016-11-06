#include<stdio.h>
#include"gdal.h"
#include"cpl_conv.h"

int main(void)
{
	GDALDatasetH hDataset;

	GDALAllRegister();

	hDataset = GDALOpen("dem.tif", GA_ReadOnly);

	printf("OK\n");
	return 0;
}

#define NODATA -9999

typedef struct Point
{
	double x;
	double y;
}Point;

typedef struct Raster
{
	double* matrix;
	Point origin;
	double xRes;
	double yRes;
	int nRow;
	int nCol;
	double xmax, ymax;
	double nodata;
}Raster, *pRaster;
